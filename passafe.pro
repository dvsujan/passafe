QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    login.cpp \
    rand_gen.cpp\
    createnew.cpp \
    qaesencryption.cpp \
    passman.cpp \
    new_entry.cpp



HEADERS += \
    mainwindow.h \
    login.h \
    rand_gen.h \
    createnew.h \
    qaesencryption.h \
    passman.h \
    new_entry.h


FORMS += \
    mainwindow.ui\
    login.ui \
    rand_gen.ui \
    createnew.ui \
    new_entry.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
