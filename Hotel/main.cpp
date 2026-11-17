// main.cpp
#include "hotel.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Hotel hotel;
    hotel.show();
    return app.exec();
}
