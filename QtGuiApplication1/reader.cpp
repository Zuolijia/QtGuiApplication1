#include "reader.h"

Reader::Reader(){}

void Reader::receiveNewspaper(const QString & name)
{
	qDebug() << "Receives Newspaper: " << name;
}