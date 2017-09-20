#ifndef MOTOR_H
#define MOTOR_H

#include <QWidget>

namespace Ui {
class Motor;
}

class Motor : public QWidget
{
    Q_OBJECT

public:
    explicit Motor(QWidget *parent = 0);
    ~Motor();

private:
    Ui::Motor *ui;
};

#endif // MOTOR_H
