#-------------------------------------------------
#
# Project created by QtCreator 2014-10-08T14:32:28
#
#-------------------------------------------------

QT       += core gui network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DownloadRRSC
TEMPLATE = app


SOURCES += main.cpp\
        mainform.cpp \
    Class/parser.cpp \
    downloadform.cpp \
    aboutform.cpp

HEADERS  += mainform.h \
    Class/parser.h \
    downloadform.h \
    aboutform.h

FORMS    += mainform.ui \
    downloadform.ui \
    aboutform.ui

OTHER_FILES += \
    README.md

RESOURCES += \
    resource.qrc
