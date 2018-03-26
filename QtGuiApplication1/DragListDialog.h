#pragma once

#include <QDialog>
#include "ui_DragListDialog.h"

class DragListDialog : public QDialog, public Ui::DragDialog
{
    Q_OBJECT

public:
    DragListDialog(QWidget *parent = Q_NULLPTR);
    ~DragListDialog();

public slots:
    void on_leftButton_clicked();
    void on_rightButton_clicked();

private:
    void moveCurrentItem(DragListWidget *source, DragListWidget *target);
};
