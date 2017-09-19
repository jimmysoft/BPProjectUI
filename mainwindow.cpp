#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configdialog.h"
#include "handler.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    handler = new Handler(this);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::changeLabel(QImage qimg)
{
    ui->label->setPixmap(QPixmap::fromImage(qimg).scaled(ui->label->size()));
}


void MainWindow::on_buttonStart_clicked()
{
    if(handler==NULL)
    {
        std::cout<<"NULL Error";
    }
    else
    {
        handler->Start();
    }
}

void MainWindow::on_buttonOnce_clicked()
{
    handler->Once();
}

void MainWindow::on_buttonStop_clicked()
{
    handler->Stop();
}

void MainWindow::on_buttonConfig_clicked()
{
    ConfigDialog configDialog(this);
    configDialog.setModal(true);
    if(configDialog.exec() == QDialog::Accepted){
        //data
        QString data = "HopperCount: "+configDialog.hopperCount+
                ", GripperOnDelay: "+configDialog.gripperOnDelay+
                ", Option1: "+configDialog.option1+
                ", Option2: "+configDialog.option2;

        //config values save in file directory is where the application in
        QFile file(QApplication::applicationDirPath()+"/config.txt");
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
        QTextStream out(&file);
        out << data;
        file.close();
    }
}


void MainWindow::on_buttonExit_clicked()
{
    destroy(true);
}
