#include "viewcustomersform.h"
#include "ui_viewcustomersform.h"
#include "centerhelper.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QHeaderView>

ViewCustomersForm::ViewCustomersForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewCustomersForm) {
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(25, 20, 25, 20);
    mainLayout->setSpacing(15);

    QLabel *titleLabel = new QLabel("Customers List", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont f = titleLabel->font();
    f.setPointSize(16);
    f.setBold(true);
    titleLabel->setFont(f);
    mainLayout->addWidget(titleLabel);

    ui->customersTableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->customersTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mainLayout->addWidget(ui->customersTableWidget);

    QPushButton *closeBtn = new QPushButton("Close", this);
    closeBtn->setMinimumSize(120, 36);
    connect(closeBtn, &QPushButton::clicked, this, &QDialog::accept);
    mainLayout->addWidget(closeBtn, 0, Qt::AlignCenter);

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
