#ifndef MOTORUNIT_H
#define MOTORUNIT_H

#include <QWidget>

namespace Ui {
class MotorUnit;
}

class MotorUnit : public QWidget
{
    Q_OBJECT

public:
    explicit MotorUnit(QWidget *parent = 0);
    ~MotorUnit();

private:
    Ui::MotorUnit *ui;
};

#endif // MOTORUNIT_H
