/********************************************************************************
** Form generated from reading UI file 'DragListDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGLISTDIALOG_H
#define UI_DRAGLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include "DragListWidget.h"

QT_BEGIN_NAMESPACE

class Ui_DragDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *labelA;
    QLabel *labelB;
    DragListWidget *DragListA;
    QSpacerItem *spacer_2;
    DragListWidget *DragListB;
    QToolButton *leftButton;
    QToolButton *rightButton;
    QSpacerItem *spacer;

    void setupUi(QDialog *DragDialog)
    {
        if (DragDialog->objectName().isEmpty())
            DragDialog->setObjectName(QStringLiteral("DragDialog"));
        DragDialog->resize(535, 354);
        gridLayout = new QGridLayout(DragDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelA = new QLabel(DragDialog);
        labelA->setObjectName(QStringLiteral("labelA"));
        labelA->setMouseTracking(true);
        labelA->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelA, 0, 0, 1, 1);

        labelB = new QLabel(DragDialog);
        labelB->setObjectName(QStringLiteral("labelB"));
        labelB->setMouseTracking(true);
        labelB->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelB, 0, 2, 1, 1);

        DragListA = new DragListWidget(DragDialog);
        DragListA->setObjectName(QStringLiteral("DragListA"));
        DragListA->setAutoScrollMargin(0);

        gridLayout->addWidget(DragListA, 1, 0, 4, 1);

        spacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer_2, 1, 1, 1, 1);

        DragListB = new DragListWidget(DragDialog);
        DragListB->setObjectName(QStringLiteral("DragListB"));
        DragListB->setAutoScrollMargin(0);

        gridLayout->addWidget(DragListB, 1, 2, 4, 1);

        leftButton = new QToolButton(DragDialog);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/leftarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftButton->setIcon(icon);
        leftButton->setIconSize(QSize(22, 22));

        gridLayout->addWidget(leftButton, 2, 1, 1, 1);

        rightButton = new QToolButton(DragDialog);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/rightarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        rightButton->setIcon(icon1);
        rightButton->setIconSize(QSize(22, 22));

        gridLayout->addWidget(rightButton, 3, 1, 1, 1);

        spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacer, 4, 1, 1, 1);


        retranslateUi(DragDialog);

        QMetaObject::connectSlotsByName(DragDialog);
    } // setupUi

    void retranslateUi(QDialog *DragDialog)
    {
        DragDialog->setWindowTitle(QApplication::translate("DragDialog", "Choose Drag Dialog", Q_NULLPTR));
        labelA->setText(QApplication::translate("DragDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">List A</span></p></body></html>", Q_NULLPTR));
        labelB->setText(QApplication::translate("DragDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">List B</span></p></body></html>", Q_NULLPTR));
        leftButton->setText(QApplication::translate("DragDialog", "...", Q_NULLPTR));
        rightButton->setText(QApplication::translate("DragDialog", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DragDialog: public Ui_DragDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGLISTDIALOG_H
