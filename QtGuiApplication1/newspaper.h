#pragma once

#include <QObject>
class Newspaper :public QObject
{
	Q_OBJECT
public:
	Newspaper(const QString & name);
	void send();
signals:
	void newPaper(const QString & name);
private:
	QString m_name;
};