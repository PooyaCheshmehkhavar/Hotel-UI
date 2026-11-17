#include "addnewroom.h"
#include "ui_addnewroom.h"
#include "centerhelper.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>

AddNewRoom::AddNewRoom(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddNewRoom)
{
    ui->setupUi(this);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    formLayout->setHorizontalSpacing(15);
    formLayout->setVerticalSpacing(12);

    formLayout->addRow(ui->label, ui->Capacity);
    formLayout->addRow(ui->label_2, ui->Price);
    formLayout->addRow(ui->label_3, ui->Description);

    ui->Capacity->setMinimumWidth(220);
    ui->Capacity->setMinimumHeight(28);
    ui->Price->setMinimumWidth(220);
    ui->Price->setMinimumHeight(28);
    ui->Description->setMinimumWidth(220);
    ui->Description->setMinimumHeight(28);

    QPushButton *cancelBtn = new QPushButton("Back", this);
    cancelBtn->setMinimumSize(110, 34);
    ui->saveroom->setMinimumSize(110, 34);
    connect(cancelBtn, &QPushButton::clicked, this, &QDialog::reject);

    QHBoxLayout *btnBox = new QHBoxLayout();
    btnBox->setAlignment(Qt::AlignCenter);
    btnBox->setSpacing(15);
    btnBox->addWidget(ui->saveroom);
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

    setTabOrder(ui->Capacity, ui->Price);
    setTabOrder(ui->Price, ui->Description);
    setTabOrder(ui->Description, ui->saveroom);
    setTabOrder(ui->saveroom, cancelBtn);

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
