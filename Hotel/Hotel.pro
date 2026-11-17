QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcustomerform.cpp \
    addnewroom.cpp \
    cancelrev.cpp \
    main.cpp \
    hotel.cpp \
    makereserve.cpp \
    viewcustomersform.cpp \
    viewrev.cpp \
    viewrooms.cpp

HEADERS += \
    addcustomerform.h \
    addnewroom.h \
    cancelrev.h \
    centerhelper.h \
    hotel.h \
    makereserve.h \
    viewcustomersform.h \
    viewrev.h \
    viewrooms.h

FORMS += \
    addcustomerform.ui \
    addnewroom.ui \
    cancelrev.ui \
    hotel.ui \
    makereserve.ui \
    viewcustomersform.ui \
    viewrev.ui \
    viewrooms.ui

TRANSLATIONS += \
    Hotel_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
