#include "cancelrev.h"
#include "ui_cancelrev.h"
#include "hotel.h"
#include "centerhelper.h"
#include <algorithm>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>

CancelRev::CancelRev(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CancelRev)
{
    ui->setupUi(this);

    for (const auto& r : reservation_list){
        if (r.status != "Cancelled") {
            ui->RID->addItem(QString::number(r.id));
        }
    }

    QFormLayout *formLayout = new QFormLayout();
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    formLayout->setHorizontalSpacing(15);
    formLayout->addRow(ui->label, ui->RID);
    ui->RID->setMinimumWidth(200);

    QPushButton *cancelBtn = new QPushButton("Back", this);
    cancelBtn->setMinimumSize(110, 34);
    ui->Cancelrev->setMinimumSize(140, 34);
    connect(cancelBtn, &QPushButton::clicked, this, &QDialog::reject);

    QHBoxLayout *btnBox = new QHBoxLayout();
    btnBox->setAlignment(Qt::AlignCenter);
    btnBox->setSpacing(15);
    btnBox->addWidget(ui->Cancelrev);
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

    setTabOrder(ui->RID, ui->Cancelrev);
    setTabOrder(ui->Cancelrev, cancelBtn);

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
