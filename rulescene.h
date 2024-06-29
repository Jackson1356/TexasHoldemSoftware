#ifndef RULESCENE_H
#define RULESCENE_H

#include <QMainWindow>
#include<QLabel>

namespace Ui {
class rulescene;
}

class rulescene : public QMainWindow
{
    Q_OBJECT

public:
    explicit rulescene(QWidget *parent = 0);
    ~rulescene();

    void paintEvent(QPaintEvent*);

signals:
    void ruleback();
private:
    Ui::rulescene *ui;
};

#endif // RULESCENE_H
