
#include "configdialog.h"
#include "ui_configdialog.h"

ConfigDialog::ConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);
    //config set init value
    ui->HopperCountValue->setValue(5);
    ui->GripperDelayValue->setValue(10);
    ui->Option1Value->setValue(20);
    ui->Option2Value->setValue(33);
}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}


void ConfigDialog::on_buttonBox_accepted()
{
    hopperCount = QString::number(ui->HopperCountValue->value());
    gripperOnDelay = QString::number(ui->GripperDelayValue->value());
    option1 = QString::number(ui->Option1Value->value());
    option2 = QString::number(ui->Option2Value->value());
}
