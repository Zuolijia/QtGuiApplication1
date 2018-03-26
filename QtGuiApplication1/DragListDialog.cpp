#include "DragListDialog.h"

DragListDialog::DragListDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    DragListA->addItem("Giosue Carducci");
    DragListA->addItem("Eyvind Johnson");
    DragListA->addItem("Sally Prudhomme");
    DragListA->addItem("Henryk Sienkiewicz");
    DragListA->addItem("Carl Spitteler");
    DragListA->addItem("Rabindranath Tagore");
    DragListA->addItem("Kawabata Yasunari");

    DragListB->addItem("Rudolf Eucken");
    DragListB->addItem("Anatole France");
    DragListB->addItem("Rudyard Kipling");
    DragListB->addItem("Thomas Mann");
    DragListB->addItem("Eugene O'Neill");
    DragListB->addItem("Sigrid Undset");
}

DragListDialog::~DragListDialog()
{
}

void DragListDialog::on_leftButton_clicked()
{
    moveCurrentItem(DragListB, DragListA);
}

void DragListDialog::on_rightButton_clicked()
{
    moveCurrentItem(DragListA, DragListB);
}

void DragListDialog::moveCurrentItem(DragListWidget *source, DragListWidget *target)
{
    if (source->currentItem())
    {
        QListWidgetItem *newItem = source->currentItem()->clone();
        target->addItem(newItem);
        target->setCurrentItem(newItem);
        delete source->currentItem();
    }
}
