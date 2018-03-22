#pragma once

#include <QObject>
class Newspaper :public QObject
{
	Q_OBJECT
public:
    Newspaper() {}
	Newspaper(const QString & name);
    void SetName(const QString & name);
	void send();
signals:
	void newPaper(const QString & name);
    void newPaper(const QString & name, const QDate & date);
private:
	QString m_name;
};