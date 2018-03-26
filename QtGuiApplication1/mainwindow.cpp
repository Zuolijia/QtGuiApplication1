#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QHBoxLayout>
#include <QStringList>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent)
{
	setWindowTitle(tr("Text Editor"));

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

    m_textEdit = new QTextEdit;
    m_textEdit->setAcceptDrops(false);
    setAcceptDrops(true);

    m_treeWidget.setColumnCount(1);
    QTreeWidgetItem *root = new QTreeWidgetItem(&m_treeWidget,
        QStringList(QString("Root")));
    new QTreeWidgetItem(root, QStringList(QString("Leaf 1")));
    QTreeWidgetItem *leaf2 = new QTreeWidgetItem(root, QStringList(QString("Leaf 2")));
    leaf2->setCheckState(0, Qt::Checked);

    QList<QTreeWidgetItem *> rootList;
    rootList << root;
    m_treeWidget.insertTopLevelItems(0, rootList);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(&m_treeWidget);
    layout->addWidget(m_textEdit);

    QWidget * w = new QWidget(this);
    w->setLayout(layout);
    setCentralWidget(w);

    m_textEdit->installEventFilter(this);
}

MainWindow::~MainWindow()
{
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == m_textEdit)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            qDebug() << "Ate key press" << keyEvent->key();
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return QMainWindow::eventFilter(watched, event);
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/uri-list"))
    {
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
    {
        return;
    }
    QString fileName = urls.first().toLocalFile();
    if (fileName.isEmpty())
    {
        return;
    }
    if (readFile(fileName))
    {
        setWindowTitle(tr("%1 - %2").arg(fileName, tr("Drag File")));
    }
}

void MainWindow::open()
{
	QMessageBox::information(this, tr("Information"), tr("Open"));
}

bool MainWindow::readFile(const QString &fileName)
{
    bool r = false;
    QFile file(fileName);
    QString content;
    if (file.open(QIODevice::ReadOnly))
    {
        content = file.readAll();
        r = true;
    }
    m_textEdit->setText(content);
    return r;
}
