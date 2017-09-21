#ifndef IOUNIT_H
#define IOUNIT_H

#include <QWidget>

namespace Ui {
class IOUnit;
}

class IOUnit : public QWidget
{
    Q_OBJECT

public:
    explicit IOUnit(QWidget *parent = 0);
    ~IOUnit();

private:
    Ui::IOUnit *ui;
};

#endif // IOUNIT_H
