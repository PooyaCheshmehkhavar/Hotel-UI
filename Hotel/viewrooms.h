#ifndef VIEWROOMS_H
#define VIEWROOMS_H

#include <QDialog>
#include "hotel.h"

namespace Ui {
class ViewRooms;
}

class ViewRooms : public QDialog
{
    Q_OBJECT

public:
    explicit ViewRooms(QWidget *parent = nullptr);
    ~ViewRooms();

    void LoadRooms();

private:
    Ui::ViewRooms *ui;
};

#endif
