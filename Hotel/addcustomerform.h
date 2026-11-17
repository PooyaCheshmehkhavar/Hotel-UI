#ifndef ADDCUSTOMERFORM_H
#define ADDCUSTOMERFORM_H

#include <QDialog>
#include "hotel.h"

namespace Ui {
class AddCustomerForm;
}

class AddCustomerForm : public QDialog {
    Q_OBJECT

public:
    explicit AddCustomerForm(QWidget *parent = nullptr);
    ~AddCustomerForm();

private slots:
    void on_saveButton_clicked();

private:
    Ui::AddCustomerForm *ui;
};

#endif
