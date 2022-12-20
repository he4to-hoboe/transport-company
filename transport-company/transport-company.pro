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
    flightrevenue.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    tc.h \
    drivers.h \
    driverslist.h \
    driversinputscreen.h \
    flightrevenue.h

