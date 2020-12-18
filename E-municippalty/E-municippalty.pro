QT       += core gui sql charts serialport printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Capt_Pression.cpp \
    connection.cpp \
    main.cpp \
    maintenance.cpp \
    reclamation.cpp \
    ressourcemateriel.cpp

HEADERS += \
    Capt_Pression.h \
    connection.h \
    maintenance.h \
    reclamation.h \
    ressourcemateriel.h

FORMS += \
    maintenance.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
