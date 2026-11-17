#include "makereserve.h"
#include "ui_makereserve.h"
#include "hotel.h"
#include "centerhelper.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>

makereserve::makereserve(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::makereserve)
{
    ui->setupUi(this);

    for (size_t i = 0; i < customer_list.size(); ++i) {
        const Customer& customer = customer_list[i];
        ui->CID->addItem(QString::number(customer.id) + " - " + QString::fromStdString(customer.name + " " + customer.lastname), QVariant::fromValue(customer.id));
    }

    for (size_t i = 0; i < room_list.size(); ++i) {
        const rooms& room = room_list[i];
        if (room.status == "Available") {
            ui->RID->addItem(QString::number(room.id) + " (Cap: " + QString::number(room.Capacity) + ")", QVariant::fromValue(room.id));
        }
    }

    QFormLayout *formLayout = new QFormLayout();
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    formLayout->setHorizontalSpacing(15);
    formLayout->setVerticalSpacing(12);

    formLayout->addRow(ui->label, ui->CID);
    formLayout->addRow(ui->label_2, ui->RID);
    formLayout->addRow(ui->label_3, ui->Days);

    ui->CID->setMinimumWidth(220);
    ui->RID->setMinimumWidth(220);
    ui->Days->setMinimumWidth(220);
    ui->Days->setMinimumHeight(28);

    QPushButton *cancelBtn = new QPushButton("Back", this);
    cancelBtn->setMinimumSize(110, 34);
    ui->saverev->setMinimumSize(110, 34);
    connect(cancelBtn, &QPushButton::clicked, this, &QDialog::reject);

    QHBoxLayout *btnBox = new QHBoxLayout();
    btnBox->setAlignment(Qt::AlignCenter);
    btnBox->setSpacing(15);
    btnBox->addWidget(ui->saverev);
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

    setTabOrder(ui->CID, ui->RID);
    setTabOrder(ui->RID, ui->Days);
    setTabOrder(ui->Days, ui->saverev);
    setTabOrder(ui->saverev, cancelBtn);

    ui->CID->setFocus();
    centerOnScreen(this);
}

makereserve::~makereserve()
{
    delete ui;
}

void makereserve::on_saverev_clicked(){
    int customerIndex = ui->CID->currentIndex();
    int roomIndex = ui->RID->currentIndex();

    if (customerIndex < 0 || roomIndex < 0) {
        showCenteredWarning(this, "Error", "Please select a valid customer and room.");
        return;
    }

    int customerId = ui->CID->itemData(customerIndex).toInt();
    int roomId = ui->RID->itemData(roomIndex).toInt();
    int days = ui->Days->text().toInt();

    if (days <= 0) {
        showCenteredWarning(this, "Error", "Please enter a valid number of days.");
        return;
    }

    reserve R;
    R.id = reservation_list.size() + 1;
    R.customer = customer_list[customerId - 1];
    R.room = room_list[roomId - 1];
    R.days = days;
    R.finalprice = R.days * R.room.day_price;
    R.status = "Confirmed";

    for (size_t i = 0; i < room_list.size(); ++i) {
        if (room_list[i].id == roomId) {
            room_list[i].status = "Unavailable";
            break;
        }
    }

    reservation_list.push_back(R);

    showCenteredInfo(this, "Success", "Reservation created successfully!");

    this->close();
}
