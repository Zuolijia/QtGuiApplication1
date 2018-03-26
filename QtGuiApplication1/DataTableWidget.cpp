#include "DataTableWidget.h"

DataTableWidget::DataTableWidget(QWidget *parent)
    : QTableWidget(parent)
{
    setAcceptDrops(true);
    setSelectionMode(ContiguousSelection);

    setColumnCount(3);
    setRowCount(5);
}

DataTableWidget::~DataTableWidget()
{
}

void DataTableWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        startPos = event->pos();
    }
    QTableWidget::mousePressEvent(event);
}

void DataTableWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance()) {
            performDrag();
        }
    }
}

void DataTableWidget::dragEnterEvent(QDragEnterEvent *event)
{
    DataTableWidget *source =
        qobject_cast<DataTableWidget *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void DataTableWidget::dragMoveEvent(QDragMoveEvent *event)
{
    DataTableWidget *source =
        qobject_cast<DataTableWidget *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void DataTableWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("text/csv"))
    {
        QByteArray csvData = event->mimeData()->data("text/csv");
        QString csvText = QString::fromUtf8(csvData);
        fromCsv(csvText);
        event->acceptProposedAction();
    }
}

void DataTableWidget::performDrag()
{
    QString selectedString = selectionText();
    if (selectionText().isEmpty())
        return;

    QMimeData *mimeData = new QMimeData;
    mimeData->setHtml(toHtml(selectedString));
    mimeData->setData("text/csv", toCsv(selectedString).toUtf8());

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    if (drag->exec(Qt::CopyAction | Qt::MoveAction) == Qt::MoveAction)
    {
        selectionModel()->clearSelection();
    }
}

QString DataTableWidget::selectionText() const
{
    QString selectionString;
    QString headerString;
    QAbstractItemModel *itemModel = model();
    QTableWidgetSelectionRange selection = selectedRanges().at(0);
    for (int row = selection.topRow(), firstRow = row;
        row <= selection.bottomRow(); ++row)
    {
        for (int col = selection.leftColumn();
            col <= selection.rightColumn(); ++col)
        {
            if (row == firstRow)
            {
                headerString.append(horizontalHeaderItem(col)->text()).append("\t");
            }
            QModelIndex index = itemModel->index(row, col);
            selectionString.append(index.data().toString());
        }
        selectionString = selectionString.trimmed();
        selectionString.append("\n");
    }
    return headerString.trimmed() + "\n" + selectionString.trimmed();
}

QString DataTableWidget::toHtml(const QString &plainText) const
{
#if QT_VERSION >= 0x050000
    QString result = plainText.toHtmlEscaped();
#else
    QString result = Qt::escape(plainText);
#endif
    result.replace("\t", "<td>");
    result.replace("\n", "\n<tr><td>");
    result.prepend("<table>\n<tr><td>");
    result.append("\n</table>");
    return result;
}

QString DataTableWidget::toCsv(const QString &plainText) const
{
    QString result = plainText;
    result.replace("\\", "\\\\");
    result.replace("\"", "\\\"");
    result.replace("\t", "\", \"");
    result.replace("\n", "\"\n\"");
    result.prepend("\"");
    result.append("\"");
    return result;
}

void DataTableWidget::fromCsv(const QString &csvText)
{
    QStringList rows = csvText.split("\n");
    QStringList headers = rows.at(0).split(", ");
    for (int h = 0; h < headers.size(); ++h) {
        QString header = headers.at(0);
        headers.replace(h, header.replace('"', ""));
    }
    setHorizontalHeaderLabels(headers);
    for (int r = 1; r < rows.size(); ++r) {
        QStringList row = rows.at(r).split(", ");
        setItem(r - 1, 0, new QTableWidgetItem(row.at(0).trimmed().replace('"', "")));
        setItem(r - 1, 1, new QTableWidgetItem(row.at(1).trimmed().replace('"', "")));
    }
}

void InitTable(DataTableWidget *topTable)
{
    QStringList headers;
    headers << "ID" << "Name" << "Age";
    topTable->setHorizontalHeaderLabels(headers);
    topTable->setItem(0, 0, new QTableWidgetItem(QString("0001")));
    topTable->setItem(0, 1, new QTableWidgetItem(QString("Anna")));
    topTable->setItem(0, 2, new QTableWidgetItem(QString("20")));
    topTable->setItem(1, 0, new QTableWidgetItem(QString("0002")));
    topTable->setItem(1, 1, new QTableWidgetItem(QString("Tommy")));
    topTable->setItem(1, 2, new QTableWidgetItem(QString("21")));
    topTable->setItem(2, 0, new QTableWidgetItem(QString("0003")));
    topTable->setItem(2, 1, new QTableWidgetItem(QString("Jim")));
    topTable->setItem(2, 2, new QTableWidgetItem(QString("21")));
    topTable->setItem(3, 0, new QTableWidgetItem(QString("0004")));
    topTable->setItem(3, 1, new QTableWidgetItem(QString("Dick")));
    topTable->setItem(3, 2, new QTableWidgetItem(QString("24")));
    topTable->setItem(4, 0, new QTableWidgetItem(QString("0005")));
    topTable->setItem(4, 1, new QTableWidgetItem(QString("Tim")));
    topTable->setItem(4, 2, new QTableWidgetItem(QString("22")));
}
