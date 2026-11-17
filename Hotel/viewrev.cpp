#include "viewrev.h"
#include "ui_viewrev.h"
#include "centerhelper.h"

viewrev::viewrev(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::viewrev)
{
    ui->setupUi(this);
    centerOnScreen(this);
    LoadRevs();
}

viewrev::~viewrev()
{
    delete ui;
}

void viewrev::LoadRevs(){
    ui->reserve->setRowCount(reservation_list.size());
    ui->reserve->setColumnCount(6);

    QStringList headers;
    headers << "Reserve's ID" << "Customer's ID" << "Room's ID" << "Days to rent" << "Final price" << "Status";
    ui->reserve->setHorizontalHeaderLabels(headers);

    for (size_t i = 0; i < reservation_list.size(); ++i) {
        ui->reserve->setItem(i, 0, new QTableWidgetItem(QString::number(reservation_list[i].id)));
        ui->reserve->setItem(i, 1, new QTableWidgetItem(QString::number(reservation_list[i].customer.id)));
        ui->reserve->setItem(i, 2, new QTableWidgetItem(QString::number(reservation_list[i].room.id)));
        ui->reserve->setItem(i, 3, new QTableWidgetItem(QString::number(reservation_list[i].days)));
        ui->reserve->setItem(i, 4, new QTableWidgetItem(QString::number(reservation_list[i].finalprice)));
        ui->reserve->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(reservation_list[i].status)));
    }
}
