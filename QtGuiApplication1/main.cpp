#include <QApplication>
#include <QDebug>
#include <QCoreApplication>
#include <QLabel>
#include <QMouseEvent>
#include <QTableView>

#include "mainwindow.h"
#include "newspaper.h"
#include "reader.h"
#include "CustomButton.h"
#include "CurrencyModel.h"
#include "DragListDialog.h"
#include "DataTableWidget.h"
#include "ClipboardDemo.h"

class EventLabel :public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

void EventLabel::mouseMoveEvent(QMouseEvent *ev)
{
    this->setText(QString("<center><h1>Move:(%1,%2)</h1></center>")
        .arg(QString::number(ev->x()), QString::number(ev->y())));
}

void EventLabel::mousePressEvent(QMouseEvent *ev)
{
    this->setText(QString("<center><h1>Press:(%1,%2)</h1></center>")
        .arg(QString::number(ev->x()), QString::number(ev->y())));
}

void EventLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString msg;
    msg.sprintf("<center><h1>Release:(%d,%d)</h1></center>", ev->x(), ev->y());
    this->setText(msg);
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

    /*MainWindow win;
    win.show();*/

    /*EventLabel *label = new EventLabel;
    label->setWindowTitle("MouseEvent Demo");
    label->resize(300, 200);
    label->setMouseTracking(true);
    label->show();*/

    /*CustomButton btn;
    btn.setText(QObject::tr("This is a Button"));
    btn.show();*/

    /*QMap<QString, double> data;
    data["USD"] = 1.0000;
    data["CNY"] = 0.1628;
    data["GBP"] = 1.5361;
    data["EUR"] = 1.2992;
    data["HKD"] = 0.1289;

    QTableView view;
    CurrencyModel *model = new CurrencyModel(&view);
    model->setCurrencyMap(data);
    view.setModel(model);
    view.resize(600, 200);
    view.show();*/

    /*DragListDialog dialog;
    dialog.show();*/

    /*QWidget content;
    DataTableWidget *topTable = new DataTableWidget(&content);
    InitTable(topTable);

    DataTableWidget *bottomTable = new DataTableWidget(&content);

    QVBoxLayout *layout = new QVBoxLayout(&content);
    layout->addWidget(topTable);
    layout->addWidget(bottomTable);
    content.show();*/

    ClipboardDemo clipdemo;
    clipdemo.show();
	
	return app.exec();
}
