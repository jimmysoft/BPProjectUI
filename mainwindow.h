#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_buttonStart_clicked();

    void on_buttonOnce_clicked();

    void on_buttonStop_clicked();

    void on_buttonConfig_clicked();

    void on_buttonExit_clicked();

public slots:
     void changeLabel(QImage);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
