#pragma once

#include <QDialog>
#include "ui_testuidialog.h"

class testuidialog : public QDialog, public Ui::testuidialog
{
    Q_OBJECT

public:
    testuidialog(QWidget *parent = Q_NULLPTR);
    ~testuidialog();
};
