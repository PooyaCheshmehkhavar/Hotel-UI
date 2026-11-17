#ifndef HOTEL_H
#define HOTEL_H

#include <QMainWindow>
#include <vector>
#include <string>

struct Address {
    std::string street;
    std::string city;
    std::string country;
};


struct Date {
    int day;
    int month;
    int year;
};


struct Customer {
    int id;
    std::string name;
    std::string lastname;
    std::string mobile;
    std::string email;
    Address address;
    Date date;
};

struct rooms {
    int id = 0;
    long long int day_price;
    int Capacity;
    std::string Description;
    std::string status = "Available";
};

struct reserve {
    int id = 0;
    Customer customer;
    rooms room;
    int days;
    int finalprice;
    std::string status = "Confirm";
};

extern std::vector<Customer> customer_list;
extern std::vector<rooms> room_list;
extern std::vector<reserve> reservation_list;

namespace Ui {
class Hotel;
}

class Hotel : public QMainWindow {
    Q_OBJECT

public:
    explicit Hotel(QWidget *parent = nullptr);
    ~Hotel();

private slots:
    void on_addCustomerButton_clicked();
    void on_viewCustomersButton_clicked();

    void on_AddNewRoomButton_clicked();

    void on_ViewRooms_clicked();

    void on_MakeRev_clicked();

    void on_ViewRev_clicked();

    void on_CancelRev_clicked();

private:
    Ui::Hotel *ui;
};

#endif
