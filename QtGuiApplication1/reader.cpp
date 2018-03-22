#include "reader.h"

Reader::Reader(){}

void Reader::receiveNewspaper(const QString & name, const QDate & date /*= QDate::currentDate()*/)
{
	qDebug() << "Receives Newspaper: " << name;
    qDebug() << "Receives Date:" << date;
}