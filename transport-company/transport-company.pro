TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    tc.cpp \
    transport-company.cpp \
    drivers.cpp \
    driverslist.cpp \
    driversinputscreen.cpp \
    flightrevenue.cpp \
    revrecord.cpp \
    revinputscreen.cpp \
    expenserecord.cpp \
    expenseinputscreen.cpp \
    annualreport.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    tc.h \
    drivers.h \
    driverslist.h \
    driversinputscreen.h \
    flightrevenue.h \
    revrecord.h \
    revinputscreen.h \
    expense.h \
    expenserecord.h \
    expenseinputscreen.h \
    annualreport.h

