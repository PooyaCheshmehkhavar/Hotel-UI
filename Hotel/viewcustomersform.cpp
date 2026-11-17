#include "viewcustomersform.h"
#include "ui_viewcustomersform.h"
#include "centerhelper.h"

ViewCustomersForm::ViewCustomersForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewCustomersForm) {
    ui->setupUi(this);

    centerOnScreen(this);
    loadCustomers();
}

ViewCustomersForm::~ViewCustomersForm() {
    delete ui;
}

void ViewCustomersForm::loadCustomers() {
    ui->customersTableWidget->setRowCount(customer_list.size());
    ui->customersTableWidget->setColumnCount(11);

    QStringList headers;
    headers << "ID" << "Name" << "Last Name" << "Year" << "Month" << "Day" << "Phone" << "Street" << "City" << "Country" << "Email";
    ui->customersTableWidget->setHorizontalHeaderLabels(headers);

    for (size_t i = 0; i < customer_list.size(); ++i) {
        ui->customersTableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(customer_list[i].id)));
        ui->customersTableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(customer_list[i].name)));
        ui->customersTableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(customer_list[i].lastname)));
        ui->customersTableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(customer_list[i].date.year)));
        ui->customersTableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(customer_list[i].date.month)));
        ui->customersTableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(customer_list[i].date.day)));
        ui->customersTableWidget->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(customer_list[i].mobile)));
        ui->customersTableWidget->setItem(i, 7, new QTableWidgetItem(QString::fromStdString(customer_list[i].address.street)));
        ui->customersTableWidget->setItem(i, 8, new QTableWidgetItem(QString::fromStdString(customer_list[i].address.city)));
        ui->customersTableWidget->setItem(i, 9, new QTableWidgetItem(QString::fromStdString(customer_list[i].address.country)));
        ui->customersTableWidget->setItem(i, 10, new QTableWidgetItem(QString::fromStdString(customer_list[i].email)));
    }
}
