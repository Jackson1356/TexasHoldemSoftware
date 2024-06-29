#ifndef SELECTSCENE_H
#define SELECTSCENE_H

#include <QMainWindow>
#include<QLabel>
#include<playscene.h>
#include<playscene2.h>

namespace Ui {
class selectscene;
}

class selectscene : public QMainWindow
{
    Q_OBJECT

public:
    explicit selectscene(QWidget *parent = 0);
    ~selectscene();

    void paintEvent(QPaintEvent*);
    playscene * play=NULL;
    playscene2 * play2=NULL;
signals:
    void selectback();

private:
    Ui::selectscene *ui;
};

#endif // SELECTSCENE_H
