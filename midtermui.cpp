#include "midtermui.h"
#include "ui_midtermui.h"

MidTermUi::MidTermUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MidTermUi)
{
    ui->setupUi(this);
}

MidTermUi::~MidTermUi()
{
    delete ui;
}
