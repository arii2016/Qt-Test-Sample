#include <QPlainTextEdit>

#include "BaseWindow.h"
#include "ui_BaseWindow.h"

BaseWindow::BaseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BaseWindow)
{
    ui->setupUi(this);
    init();
}

BaseWindow::~BaseWindow()
{
    delete ui;
}

void BaseWindow::init()
{
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(onClickOk()));
}

void BaseWindow::onClickOk()
{
    ui->outputText->clear();
    ui->outputText->setText( ui->inputText->toPlainText() );
}
