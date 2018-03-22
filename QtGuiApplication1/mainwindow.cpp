#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent)
{
	setWindowTitle(tr("Main Window"));

	openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
	openAction->setShortcuts(QKeySequence::Open);
	openAction->setStatusTip(tr("Open an existing file"));
	connect(openAction, &QAction::triggered, this, &MainWindow::open);

	QMenu *file = menuBar()->addMenu(tr("&File"));
	file->addAction(openAction);

    m_newspaper.SetName("Newpaper A");
    /*QObject::connect(&m_newspaper,
        static_cast<void (Newspaper:: *)(const QString &, const QDate &)>(&Newspaper::newPaper),
        &m_reader,
        &Reader::receiveNewspaper);*/
    /*QObject::connect(&m_newspaper, 
        static_cast<void (Newspaper:: *)(const QString &)>(&Newspaper::newPaper),
        &m_reader, 
        &Reader::receiveNewspaper);*/
    QObject::connect(&m_newspaper,
        static_cast<void (Newspaper:: *)(const QString &)>(&Newspaper::newPaper),
        [=](const QString &name) {m_reader.receiveNewspaper(name); });

    sendpaperAction = new QAction(tr("Send"),this);
    sendpaperAction->setStatusTip(tr("Send Newspaper"));
    connect(sendpaperAction, &QAction::triggered, &m_newspaper, &Newspaper::send);
	QToolBar *toolBar = addToolBar(tr("SendNews"));
	toolBar->addAction(sendpaperAction);

	statusBar();
}

MainWindow::~MainWindow()
{
}

void MainWindow::open()
{
	QMessageBox::information(this, tr("Information"), tr("Open"));
}