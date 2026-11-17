#include "addnewroom.h"
#include "ui_addnewroom.h"
#include "centerhelper.h"

AddNewRoom::AddNewRoom(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddNewRoom)
{
    ui->setupUi(this);

    // Set tab order
    setTabOrder(ui->Capacity, ui->Price);
    setTabOrder(ui->Price, ui->Description);
    setTabOrder(ui->Description, ui->saveroom);

    ui->Capacity->setFocus();
    centerOnScreen(this);
}

AddNewRoom::~AddNewRoom()
{
    delete ui;
}

void AddNewRoom::on_saveroom_clicked()
{
    rooms Room;
    Room.id = room_list.size() + 1;
    Room.Capacity = ui->Capacity->text().toInt();
    Room.day_price = ui->Price->text().toInt();
    Room.Description = ui->Description->text().toStdString();

    if(ui->Capacity->text().isEmpty() or ui->Price->text().isEmpty()){
        showCenteredWarning(this, "Error", "All fields must be filled!");
        return;
    }

    room_list.push_back(Room);

    showCenteredInfo(this, "Success", "Room saved successfully!");

    this->close();
}
