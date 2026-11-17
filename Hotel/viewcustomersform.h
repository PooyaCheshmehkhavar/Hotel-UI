#ifndef VIEWCUSTOMERSFORM_H
#define VIEWCUSTOMERSFORM_H

#include <QDialog>
#include "hotel.h"

namespace Ui {
class ViewCustomersForm;
}

class ViewCustomersForm : public QDialog {
    Q_OBJECT

public:
    explicit ViewCustomersForm(QWidget *parent = nullptr);
    ~ViewCustomersForm();

    void loadCustomers();

private:
    Ui::ViewCustomersForm *ui;
};

#endif
