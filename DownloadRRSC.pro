#-------------------------------------------------
#
# Project created by QtCreator 2014-10-08T14:32:28
#
#-------------------------------------------------

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DownloadRRSC
TEMPLATE = app


SOURCES += main.cpp\
        mainform.cpp \
    Class/parser.cpp

HEADERS  += mainform.h \
    Class/parser.h

FORMS    += mainform.ui

OTHER_FILES += \
    README.md
