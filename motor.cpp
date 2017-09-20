#include "motor.h"
#include "ui_motor.h"

Motor::Motor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Motor)
{
    ui->setupUi(this);
}

Motor::~Motor()
{
    delete ui;
}
