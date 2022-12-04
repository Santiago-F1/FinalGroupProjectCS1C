QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addmembers.cpp \
    addtrans.cpp \
    admin.cpp \
    database.cpp \
    inventory.cpp \
    loginui.cpp \
    main.cpp \
    mempurchases.cpp \
    memstatus.cpp \
    rebate.cpp \
    salesreport.cpp \
    searchitem.cpp \
    storemanager.cpp \
    storeproducts.cpp \
    updateexec.cpp \
    updatemembers.cpp

HEADERS += \
    addmembers.h \
    addtrans.h \
    admin.h \
    database.h \
    inventory.h \
    loginui.h \
    mempurchases.h \
    memstatus.h \
    rebate.h \
    salesreport.h \
    searchitem.h \
    storemanager.h \
    storeproducts.h \
    updateexec.h \
    updatemembers.h

FORMS += \
    addmembers.ui \
    addtrans.ui \
    admin.ui \
    inventory.ui \
    loginui.ui \
    mempurchases.ui \
    memstatus.ui \
    rebate.ui \
    salesreport.ui \
    searchitem.ui \
    storemanager.ui \
    storeproducts.ui \
    updateexec.ui \
    updatemembers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    items.db
