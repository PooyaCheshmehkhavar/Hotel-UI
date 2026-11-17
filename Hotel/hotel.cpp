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

std::vector<Customer> customer_list;
std::vector<rooms> room_list;
std::vector<reserve> reservation_list;

Hotel::Hotel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hotel) {
    ui->setupUi(this);

    // Set tab order across main window buttons
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
    AddCustomerForm addCustomerForm(this);
    addCustomerForm.exec();
}

void Hotel::on_viewCustomersButton_clicked(){
    ViewCustomersForm viewCustomersForm(this);
    viewCustomersForm.exec();
}

void Hotel::on_AddNewRoomButton_clicked(){
    AddNewRoom addNewRoom(this);
    addNewRoom.exec();
}

void Hotel::on_ViewRooms_clicked(){
    ViewRooms viewRooms(this);
    viewRooms.exec();
}

void Hotel::on_MakeRev_clicked(){
    makereserve makeReserve(this);
    makeReserve.exec();
}

void Hotel::on_ViewRev_clicked()
{
    viewrev viewRev(this);
    viewRev.exec();
}

void Hotel::on_CancelRev_clicked(){
    CancelRev cancelRev(this);
    cancelRev.exec();
}
