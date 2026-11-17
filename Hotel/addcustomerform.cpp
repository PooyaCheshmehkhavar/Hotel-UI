#include "addcustomerform.h"
#include "ui_addcustomerform.h"
#include "centerhelper.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>

AddCustomerForm::AddCustomerForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCustomerForm) {
    ui->setupUi(this);

    // Responsive centered form layout
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    formLayout->setHorizontalSpacing(15);
    formLayout->setVerticalSpacing(10);

    formLayout->addRow(ui->label, ui->nameLineEdit);
    formLayout->addRow(ui->label_2, ui->lastnameLineEdit);
    formLayout->addRow(ui->label_3, ui->phoneLineEdit);
    formLayout->addRow(ui->label_4, ui->dayLineEdit);
    formLayout->addRow(ui->label_5, ui->monthLineEdit);
    formLayout->addRow(ui->label_6, ui->yearLineEdit);
    formLayout->addRow(ui->label_7, ui->streetLineEdit);
    formLayout->addRow(ui->label_8, ui->cityLineEdit);
    formLayout->addRow(ui->label_9, ui->countryLineEdit);
    formLayout->addRow(ui->label_10, ui->emailLineEdit);

    int fieldWidth = 240;
    for (QLineEdit *le : {ui->nameLineEdit, ui->lastnameLineEdit, ui->phoneLineEdit,
                          ui->dayLineEdit, ui->monthLineEdit, ui->yearLineEdit,
                          ui->streetLineEdit, ui->cityLineEdit, ui->countryLineEdit, ui->emailLineEdit}) {
        le->setMinimumWidth(fieldWidth);
        le->setMinimumHeight(28);
    }

    QPushButton *cancelBtn = new QPushButton("Back", this);
    cancelBtn->setMinimumSize(110, 34);
    ui->saveButton->setMinimumSize(110, 34);
    connect(cancelBtn, &QPushButton::clicked, this, &QDialog::reject);

    QHBoxLayout *btnBox = new QHBoxLayout();
    btnBox->setAlignment(Qt::AlignCenter);
    btnBox->setSpacing(15);
    btnBox->addWidget(ui->saveButton);
    btnBox->addWidget(cancelBtn);

    QVBoxLayout *centerVBox = new QVBoxLayout();
    centerVBox->addStretch(1);
    centerVBox->addLayout(formLayout);
    centerVBox->addSpacing(15);
    centerVBox->addLayout(btnBox);
    centerVBox->addStretch(1);

    QHBoxLayout *mainHBox = new QHBoxLayout(this);
    mainHBox->addStretch(1);
    mainHBox->addLayout(centerVBox);
    mainHBox->addStretch(1);

    // Set tab order
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
    setTabOrder(ui->saveButton, cancelBtn);

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
