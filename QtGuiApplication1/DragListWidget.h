#pragma once
#include <QApplication>
#include <QListWidget>
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>

class DragListWidget : public QListWidget
{
    Q_OBJECT

public:
    DragListWidget(QWidget *parent);
    ~DragListWidget();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

private:
    void performDrag();

    QPoint m_startPos;
};
