#ifndef VIEWREV_H
#define VIEWREV_H

#include <QDialog>
#include "hotel.h"

namespace Ui {
class viewrev;
}

class viewrev : public QDialog
{
    Q_OBJECT

public:
    explicit viewrev(QWidget *parent = nullptr);
    ~viewrev();

    void LoadRevs();

private:
    Ui::viewrev *ui;
};

#endif
