TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    transport-company.cpp \
    drivers.cpp \
    driverslist.cpp \
    driversinputscreen.cpp \
    flightrevenue.cpp \
    revrecord.cpp \
    revinputscreen.cpp \
    expenserecord.cpp \
    expenseinputscreen.cpp \
    annualreport.cpp \
    UserInterface.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    drivers.h \
    driverslist.h \
    driversinputscreen.h \
    flightrevenue.h \
    revrecord.h \
    revinputscreen.h \
    expense.h \
    expenserecord.h \
    expenseinputscreen.h \
    annualreport.h \
    UserInterface.h

