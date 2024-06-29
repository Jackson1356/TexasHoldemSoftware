#ifndef BETTINGCONTROL_H
#define BETTINGCONTROL_H

#include <QWidget>

namespace Ui {
class BettingControl;
}

class BettingControl : public QWidget
{
    Q_OBJECT

public:
    explicit BettingControl(QWidget *parent = 0);
    ~BettingControl();


    void setbet(int a);
    int getbet();
    void setvalue(int a,int b);
private:
    Ui::BettingControl *ui;
};

#endif // BETTINGCONTROL_H
