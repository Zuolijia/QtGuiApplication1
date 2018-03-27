#include "NetWorker.h"
#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonParseError>

#include "weather.h"

NetWorker* NetWorker::instance()
{
    static NetWorker netWorker;
    return &netWorker;
}

NetWorker::~NetWorker()
{
    delete d;
    d = 0;
}

void NetWorker::get(const QString &url)
{
    d->manager->get(QNetworkRequest(QUrl(url)));
}

void NetWorker::handler(QNetworkReply *reply)
{
    qDebug() << reply;
    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll(), &error);
    if (error.error == QJsonParseError::NoError)
    {
        if (!(jsonDocument.isNull() || jsonDocument.isEmpty()) && jsonDocument.isObject())
        {
            QVariantMap data = jsonDocument.toVariant().toMap();
            WeatherInfo weather;
            weather.setCityName(data[QLatin1String("name")].toString());
            weather.setId(data[QLatin1String("id")].toUInt());
            QDateTime dateTime;
            dateTime.setTime_t(data[QLatin1String("dt")].toLongLong());
            weather.setDateTime(dateTime);
            QVariantMap main = data[QLatin1String("main")].toMap();
            weather.setTemperature(main[QLatin1String("temp")].toFloat());
            weather.setPressure(main[QLatin1String("pressure")].toFloat());
            weather.setHumidity(main[QLatin1String("humidity")].toFloat());
            QVariantList detailList = data[QLatin1String("weather")].toList();
            QList<WeatherDetail *> details;
            foreach(QVariant w, detailList) {
                QVariantMap wm = w.toMap();
                WeatherDetail *detail = new WeatherDetail;
                detail->setDesc(wm[QLatin1String("description")].toString());
                detail->setIcon(wm[QLatin1String("icon")].toString());
                details.append(detail);
            }
            weather.setDetails(details);
            qDebug() << weather;
        }
    }
    reply->deleteLater();
}

NetWorker::NetWorker(QObject *parent /*= 0*/):
    QObject(parent),
    d(new NetWorker::Private(this))
{
    connect(d->manager, &QNetworkAccessManager::finished,
        this, &NetWorker::finished);
    connect(this, &NetWorker::finished, this, &NetWorker::handler);
}

NetWorker::Private::Private(NetWorker *q) :manager(new QNetworkAccessManager(q))
{

}
