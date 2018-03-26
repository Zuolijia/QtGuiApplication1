#include "DragListWidget.h"

DragListWidget::DragListWidget(QWidget *parent)
    : QListWidget(parent)
{
    setAcceptDrops(true);
}

DragListWidget::~DragListWidget()
{
}

void DragListWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_startPos = event->pos();
    }
    QListWidget::mousePressEvent(event);
}

void DragListWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        int distance = (event->pos() - m_startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
        {
            performDrag();
        }
    }
    QListWidget::mouseMoveEvent(event);
}

void DragListWidget::dragEnterEvent(QDragEnterEvent *event)
{
    DragListWidget *source =
        qobject_cast<DragListWidget *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void DragListWidget::dragMoveEvent(QDragMoveEvent *event)
{
    DragListWidget *source =
        qobject_cast<DragListWidget *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void DragListWidget::dropEvent(QDropEvent *event)
{
    DragListWidget *source =
        qobject_cast<DragListWidget *>(event->source());
    if (source && source != this) {
        addItem(event->mimeData()->text());
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void DragListWidget::performDrag()
{
    QListWidgetItem *item = currentItem();
    if (item)
    {
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(item->text());

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(QPixmap(":/Resources/person.png"));
        if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
        {
            delete item;
        }
    }
}
