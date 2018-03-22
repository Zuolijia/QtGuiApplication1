#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "newspaper.h"
#include "reader.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	void open();

	QAction *openAction;
    QAction *sendpaperAction;
    Newspaper m_newspaper;
    Reader    m_reader;
};

#endif // MAINWINDOW_H