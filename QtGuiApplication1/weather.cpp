#include "weather.h"
#include <QDebug>

QDebug operator<<(QDebug dbg, const WeatherDetail &w)
{
    dbg.nospace() << "("
        << "Description: " << w.desc() << "; "
        << "Icon: " << w.icon()
        << ")";
    return dbg.space();
}

QDebug operator<<(QDebug dbg, const WeatherInfo &w)
{
    dbg.nospace() << "("
        << "id: " << w.id() << "; "
        << "City name: " << w.cityName() << "; "
        << "Date time: " << w.dateTime().toString(Qt::DefaultLocaleLongDate) << ": " << endl
        << "Temperature: " << w.temperature() << ", "
        << "Pressure: " << w.pressure() << ", "
        << "Humidity: " << w.humidity() << ", "
        << "Details: [";
    foreach(WeatherDetail *detail, w.details())
    {
        dbg.nospace() << "( Description: " << detail->desc() << ", "
            << "Icon: " << detail->icon() << "), ";
    }
    dbg.nospace() << "] )";
    return dbg.space();

}

WeatherDetail::Private::Private()
{

}

WeatherDetail::WeatherDetail()
{

}

WeatherDetail::~WeatherDetail()
{

}

QString WeatherDetail::desc() const
{
    return d->m_desc;
}

void WeatherDetail::setDesc(const QString &desc)
{
    d->m_desc = desc;
}

QString WeatherDetail::icon() const
{
    return d->m_icon;
}

void WeatherDetail::setIcon(const QString &icon)
{
    d->m_icon = icon;
}

WeatherInfo::WeatherInfo()
{

}

WeatherInfo::~WeatherInfo()
{

}

QString WeatherInfo::cityName() const
{
    return d->m_cityname;
}

void WeatherInfo::setCityName(const QString &cityName)
{
    d->m_cityname = cityName;
}

quint32 WeatherInfo::id() const
{
    return d->m_id;
}

void WeatherInfo::setId(quint32 id)
{
    d->m_id = id;
}

QDateTime WeatherInfo::dateTime() const
{
    return d->m_datetime;
}

void WeatherInfo::setDateTime(const QDateTime &dateTime)
{
    d->m_datetime = dateTime;
}

float WeatherInfo::temperature() const
{
    return d->m_temperature;
}

void WeatherInfo::setTemperature(float temperature)
{
    d->m_temperature = temperature;
}

float WeatherInfo::humidity() const
{
    return d->m_humidity;
}

void WeatherInfo::setHumidity(float humidity)
{
    d->m_humidity = humidity;
}

float WeatherInfo::pressure() const
{
    return d->m_pressure;
}

void WeatherInfo::setPressure(float pressure)
{
    d->m_pressure = pressure;
}

QList<WeatherDetail*> WeatherInfo::details() const
{
    return d->m_details;
}

void WeatherInfo::setDetails(const QList<WeatherDetail*> details)
{
    d->m_details = details;
}
