#include "motorunit.h"
#include "ui_motorunit.h"

MotorUnit::MotorUnit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MotorUnit)
{
    ui->setupUi(this);
}

MotorUnit::~MotorUnit()
{
    delete ui;
}
