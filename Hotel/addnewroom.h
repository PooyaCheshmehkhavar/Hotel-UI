#ifndef ADDNEWROOM_H
#define ADDNEWROOM_H

#include <QDialog>
#include "hotel.h"

namespace Ui {
class AddNewRoom;
}

class AddNewRoom : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewRoom(QWidget *parent = nullptr);
    ~AddNewRoom();

private slots:

    void on_saveroom_clicked();

private:
    Ui::AddNewRoom *ui;
};

#endif
