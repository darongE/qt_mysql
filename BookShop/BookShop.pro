QMAKE_MAC_SDK = macosx10.11

QT += network\
    sql\
    testlib\
    widgets\

FORMS += \
    mainwindow.ui \
    dbookinfo.ui \
    loginwin.ui \
    adminform.ui

HEADERS += \
    mainwindow.h \
    dbookinfo.h \
    loginwin.h \
    adminform.h

SOURCES += \
    mainwindow.cpp \
    dbookinfo.cpp \
    loginwin.cpp \
    main.cpp \
    adminform.cpp

RESOURCES +=
