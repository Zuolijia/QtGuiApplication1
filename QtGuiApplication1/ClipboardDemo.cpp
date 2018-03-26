#include "ClipboardDemo.h"
#include <QtGui>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QApplication>
#include <QMessageBox>

ClipboardDemo::ClipboardDemo(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *northLayout = new QHBoxLayout;
    QHBoxLayout *southLayout = new QHBoxLayout;

    QTextEdit *editor = new QTextEdit;
    QLabel *label = new QLabel;
    label->setText(tr("Text Input"));
    label->setBuddy(editor);
    QPushButton *copyButton = new QPushButton;
    copyButton->setText(tr("Set Clipboard"));
    QPushButton *pasteButton = new QPushButton;
    pasteButton->setText(tr("Get Clipboard"));

    northLayout->addWidget(label);
    northLayout->addWidget(editor);
    southLayout->addWidget(copyButton);
    southLayout->addWidget(pasteButton);
    mainLayout->addLayout(northLayout);
    mainLayout->addLayout(southLayout);

    connect(copyButton, &QPushButton::clicked, this, &ClipboardDemo::setClipboardContent);
    connect(pasteButton, &QPushButton::clicked, this, &ClipboardDemo::getClipboardContent);
}

ClipboardDemo::~ClipboardDemo()
{
}

void ClipboardDemo::setClipboardContent()
{
    QClipboard *board = QApplication::clipboard();
    board->setText("Text from Qt Application");
}

void ClipboardDemo::getClipboardContent()
{
    QClipboard *board = QApplication::clipboard();
    QString str = board->text();
    QMessageBox::information(NULL, "From clipboard", str);
}
