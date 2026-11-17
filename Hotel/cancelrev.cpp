#include "cancelrev.h"
#include "ui_cancelrev.h"
#include "hotel.h"
#include "centerhelper.h"
#include <algorithm>

CancelRev::CancelRev(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CancelRev)
{
    ui->setupUi(this);

    for (const auto& reserve : reservation_list){
        ui->RID->addItem(QString::number(reserve.id));
    }

    // Set tab order
    setTabOrder(ui->RID, ui->Cancelrev);
    ui->RID->setFocus();
    centerOnScreen(this);
}

CancelRev::~CancelRev()
{
    delete ui;
}

void CancelRev::on_Cancelrev_clicked(){
    int reserveId = ui->RID->currentText().toInt();

    auto it = std::find_if(reservation_list.begin(), reservation_list.end(),
                           [reserveId](const reserve& r) { return r.id == reserveId; });

    if (it != reservation_list.end()) {
        it->status = "Cancelled";

        for(auto& room : room_list){
            if(room.id == it->room.id){
                room.status = "Available";
                break;
            }
        }

        showCenteredInfo(this, "Success", "Reservation canceled successfully!");
    }
    else{
        showCenteredWarning(this, "Error", "Reservation ID not found!");
    }

    this->close();
}
