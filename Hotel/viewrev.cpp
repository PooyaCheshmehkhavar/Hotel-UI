#include "viewrev.h"
#include "ui_viewrev.h"
#include "centerhelper.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QHeaderView>

viewrev::viewrev(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::viewrev)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(25, 20, 25, 20);
    mainLayout->setSpacing(15);

    QLabel *titleLabel = new QLabel("Reservations List", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont f = titleLabel->font();
    f.setPointSize(16);
    f.setBold(true);
    titleLabel->setFont(f);
    mainLayout->addWidget(titleLabel);

    ui->reserve->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->reserve->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mainLayout->addWidget(ui->reserve);

    QPushButton *closeBtn = new QPushButton("Close", this);
    closeBtn->setMinimumSize(120, 36);
    connect(closeBtn, &QPushButton::clicked, this, &QDialog::accept);
    mainLayout->addWidget(closeBtn, 0, Qt::AlignCenter);

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
