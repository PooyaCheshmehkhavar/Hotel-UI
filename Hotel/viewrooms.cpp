#include "viewrooms.h"
#include "ui_viewrooms.h"
#include "centerhelper.h"

ViewRooms::ViewRooms(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewRooms)
{
    ui->setupUi(this);

    centerOnScreen(this);
    LoadRooms();
}

ViewRooms::~ViewRooms()
{
    delete ui;
}

void ViewRooms::LoadRooms() {
    ui->Rooms->setRowCount(room_list.size());
    ui->Rooms->setColumnCount(5);

    QStringList headers;
    headers << "ID" << "Capacity" << "Price per day" << "Description" << "Status";
    ui->Rooms->setHorizontalHeaderLabels(headers);

    for (size_t i = 0; i < room_list.size(); ++i) {
        ui->Rooms->setItem(i, 0, new QTableWidgetItem(QString::number(room_list[i].id)));
        ui->Rooms->setItem(i, 1, new QTableWidgetItem(QString::number(room_list[i].Capacity)));
        ui->Rooms->setItem(i, 2, new QTableWidgetItem(QString::number(room_list[i].day_price)));
        ui->Rooms->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(room_list[i].Description)));
        ui->Rooms->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(room_list[i].status)));
    }
}
