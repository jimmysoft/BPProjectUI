#include "iounit.h"
#include "ui_iounit.h"

IOUnit::IOUnit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IOUnit)
{
    ui->setupUi(this);
}

IOUnit::~IOUnit()
{
    delete ui;
}
