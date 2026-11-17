#include "viewrooms.h"
#include "ui_viewrooms.h"
#include "centerhelper.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QHeaderView>

ViewRooms::ViewRooms(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ViewRooms)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(25, 20, 25, 20);
    mainLayout->setSpacing(15);

    QLabel *titleLabel = new QLabel("Rooms List", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont f = titleLabel->font();
    f.setPointSize(16);
    f.setBold(true);
    titleLabel->setFont(f);
    mainLayout->addWidget(titleLabel);

    ui->Rooms->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->Rooms->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mainLayout->addWidget(ui->Rooms);

    QPushButton *closeBtn = new QPushButton("Close", this);
    closeBtn->setMinimumSize(120, 36);
    connect(closeBtn, &QPushButton::clicked, this, &QDialog::accept);
    mainLayout->addWidget(closeBtn, 0, Qt::AlignCenter);

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
