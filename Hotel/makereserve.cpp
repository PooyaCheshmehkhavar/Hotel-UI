#include "makereserve.h"
#include "ui_makereserve.h"
#include "hotel.h"
#include "centerhelper.h"

makereserve::makereserve(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::makereserve)
{
    ui->setupUi(this);

    for (size_t i = 0; i < customer_list.size(); ++i) {
        const Customer& customer = customer_list[i];
        ui->CID->addItem(QString::number(customer.id), QVariant::fromValue(customer.id));
    }

    for (size_t i = 0; i < room_list.size(); ++i) {
        const rooms& room = room_list[i];
        if (room.status == "Available") {
            ui->RID->addItem(QString::number(room.id), QVariant::fromValue(room.id));
        }
    }

    // Set tab order
    setTabOrder(ui->CID, ui->RID);
    setTabOrder(ui->RID, ui->Days);
    setTabOrder(ui->Days, ui->saverev);

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
