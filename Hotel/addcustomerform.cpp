#include "addcustomerform.h"
#include "ui_addcustomerform.h"
#include "centerhelper.h"

AddCustomerForm::AddCustomerForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCustomerForm) {
    ui->setupUi(this);

    // Set tab order across fields in visual top-to-bottom sequence
    setTabOrder(ui->nameLineEdit, ui->lastnameLineEdit);
    setTabOrder(ui->lastnameLineEdit, ui->phoneLineEdit);
    setTabOrder(ui->phoneLineEdit, ui->dayLineEdit);
    setTabOrder(ui->dayLineEdit, ui->monthLineEdit);
    setTabOrder(ui->monthLineEdit, ui->yearLineEdit);
    setTabOrder(ui->yearLineEdit, ui->streetLineEdit);
    setTabOrder(ui->streetLineEdit, ui->cityLineEdit);
    setTabOrder(ui->cityLineEdit, ui->countryLineEdit);
    setTabOrder(ui->countryLineEdit, ui->emailLineEdit);
    setTabOrder(ui->emailLineEdit, ui->saveButton);

    ui->nameLineEdit->setFocus();
    centerOnScreen(this);
}

AddCustomerForm::~AddCustomerForm() {
    delete ui;
}

void AddCustomerForm::on_saveButton_clicked(){
    if (ui->nameLineEdit->text().isEmpty() or ui->lastnameLineEdit->text().isEmpty() or ui->phoneLineEdit->text().isEmpty() or ui->emailLineEdit->text().isEmpty() or
        ui->streetLineEdit->text().isEmpty() or
        ui->cityLineEdit->text().isEmpty() or
        ui->countryLineEdit->text().isEmpty() or
        ui->dayLineEdit->text().isEmpty() or
        ui->monthLineEdit->text().isEmpty() or
        ui->yearLineEdit->text().isEmpty()){
        showCenteredWarning(this, "Error", "All fields must be filled!");
        return;
    }

    Customer customer;
    customer.id = customer_list.size() + 1;
    customer.name = ui->nameLineEdit->text().toStdString();
    customer.lastname = ui->lastnameLineEdit->text().toStdString();
    customer.mobile = ui->phoneLineEdit->text().toStdString();
    customer.email = ui->emailLineEdit->text().toStdString();
    customer.address.street = ui->streetLineEdit->text().toStdString();
    customer.address.city = ui->cityLineEdit->text().toStdString();
    customer.address.country = ui->countryLineEdit->text().toStdString();

    customer.date.day = ui->dayLineEdit->text().toInt();
    customer.date.month = ui->monthLineEdit->text().toInt();
    customer.date.year = ui->yearLineEdit->text().toInt();

    if(customer.date.day <= 0 or customer.date.day > 31 or customer.date.month <= 0 or customer.date.month > 12 or customer.date.year <= 0){
        showCenteredWarning(this, "Error", "Invalid date entered!");
        return;
    }

    customer_list.push_back(customer);

    showCenteredInfo(this, "Success", "Customer saved successfully!");

    this->close();
}
