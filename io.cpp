#include "io.h"
#include "ui_io.h"

IO::IO(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IO)
{
    ui->setupUi(this);
}

IO::~IO()
{
    delete ui;
}
