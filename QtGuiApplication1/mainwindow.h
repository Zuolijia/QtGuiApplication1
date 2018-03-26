#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QEvent>
#include <QKeyEvent>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

#include "newspaper.h"
#include "reader.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private:
	void open();
    bool readFile(const QString &fileName);

	QAction *openAction;
    QAction *sendpaperAction;
    Newspaper m_newspaper;
    Reader    m_reader;

    QTextEdit *m_textEdit;
    QTreeWidget m_treeWidget;
};

#endif // MAINWINDOW_H