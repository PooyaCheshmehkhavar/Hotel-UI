#include "hotel.h"
#include "ui_hotel.h"
#include "addcustomerform.h"
#include "viewcustomersform.h"
#include "addnewroom.h"
#include "viewrooms.h"
#include "makereserve.h"
#include "viewrev.h"
#include "cancelrev.h"
#include "centerhelper.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

std::vector<Customer> customer_list;
std::vector<rooms> room_list;
std::vector<reserve> reservation_list;

Hotel::Hotel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hotel) {
    ui->setupUi(this);

    // Responsive centered layout for main window
    ui->label->setAlignment(Qt::AlignCenter);
    QFont titleFont = ui->label->font();
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    ui->label->setFont(titleFont);

    int btnWidth = 260;
    int btnHeight = 38;
    for (QPushButton *btn : {ui->addCustomerButton, ui->viewCustomersButton, ui->AddNewRoomButton,
                             ui->ViewRooms, ui->MakeRev, ui->ViewRev, ui->CancelRev, ui->pushButton_2}) {
        btn->setMinimumSize(btnWidth, btnHeight);
        btn->setMaximumSize(btnWidth, btnHeight);
        btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    }

    QVBoxLayout *vBox = new QVBoxLayout();
    vBox->setAlignment(Qt::AlignCenter);
    vBox->setSpacing(12);
    vBox->addStretch(1);
    vBox->addWidget(ui->label, 0, Qt::AlignCenter);
    vBox->addSpacing(15);
    vBox->addWidget(ui->addCustomerButton, 0, Qt::AlignCenter);
    vBox->addWidget(ui->viewCustomersButton, 0, Qt::AlignCenter);
    vBox->addWidget(ui->AddNewRoomButton, 0, Qt::AlignCenter);
    vBox->addWidget(ui->ViewRooms, 0, Qt::AlignCenter);
    vBox->addWidget(ui->MakeRev, 0, Qt::AlignCenter);
    vBox->addWidget(ui->ViewRev, 0, Qt::AlignCenter);
    vBox->addWidget(ui->CancelRev, 0, Qt::AlignCenter);
    vBox->addSpacing(10);
    vBox->addWidget(ui->pushButton_2, 0, Qt::AlignCenter);
    vBox->addStretch(1);

    QHBoxLayout *hBox = new QHBoxLayout(ui->centralwidget);
    hBox->addStretch(1);
    hBox->addLayout(vBox);
    hBox->addStretch(1);

    // Tab order across buttons
    setTabOrder(ui->addCustomerButton, ui->viewCustomersButton);
    setTabOrder(ui->viewCustomersButton, ui->AddNewRoomButton);
    setTabOrder(ui->AddNewRoomButton, ui->ViewRooms);
    setTabOrder(ui->ViewRooms, ui->MakeRev);
    setTabOrder(ui->MakeRev, ui->ViewRev);
    setTabOrder(ui->ViewRev, ui->CancelRev);
    setTabOrder(ui->CancelRev, ui->pushButton_2);

    ui->addCustomerButton->setFocus();
    centerOnScreen(this);
}

Hotel::~Hotel() {
    delete ui;
}

void Hotel::on_addCustomerButton_clicked(){
    this->hide();
    AddCustomerForm addCustomerForm(nullptr);
    addCustomerForm.exec();
    this->show();
    this->raise();
    this->activateWindow();
}

void Hotel::on_viewCustomersButton_clicked(){
    this->hide();
    ViewCustomersForm viewCustomersForm(nullptr);
    viewCustomersForm.exec();
    this->show();
    this->raise();
    this->activateWindow();
}

void Hotel::on_AddNewRoomButton_clicked(){
    this->hide();
    AddNewRoom addNewRoom(nullptr);
    addNewRoom.exec();
    this->show();
    this->raise();
    this->activateWindow();
}

void Hotel::on_ViewRooms_clicked(){
    this->hide();
    ViewRooms viewRooms(nullptr);
    viewRooms.exec();
    this->show();
    this->raise();
    this->activateWindow();
}

void Hotel::on_MakeRev_clicked(){
    this->hide();
    makereserve makeReserve(nullptr);
    makeReserve.exec();
    this->show();
    this->raise();
    this->activateWindow();
}

void Hotel::on_ViewRev_clicked()
{
    this->hide();
    viewrev viewRev(nullptr);
    viewRev.exec();
    this->show();
    this->raise();
    this->activateWindow();
}

void Hotel::on_CancelRev_clicked(){
    this->hide();
    CancelRev cancelRev(nullptr);
    cancelRev.exec();
    this->show();
    this->raise();
    this->activateWindow();
}
