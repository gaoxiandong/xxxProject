QT += core
QT -= gui

TARGET = JJBackCatchFace
TEMPLATE = app
VERSION = 0.0.0.1

CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

OUTPUT_DIR = $$PWD/..
include ($$PWD/../common.pri)
include(mainframe/mainframe.pri)
include(utils/utils.pri)

INCLUDEPATH += \
    $$PWD/mainframe \
    $$PWD/utils

INCLUDEPATH += \
    $$PWD/mainframe \
    $$PWD/utils \
    $$PWD/../include \
    /usr/local/include \
    /Users/gaoxd/GitCode/dlib \
    /Users/gaoxd/GitCode/opencv-2.4.13.3/install/include \
    /Users/mrwang/thrift-0.9.3/install/include


unix: LIBS += -L$$LIB_DIR \
            -lopencv_core.2.4 \
            -lopencv_imgproc.2.4 \
            -lopencv_highgui.2.4 \
            -lopencv_video.2.4

unix: LIBS += -L$$LIB_DIR \
            -lthriftnb-0.9.3 \
            -lthrift-0.9.3 \
            -lprotobuf.10 \
            -lboost_system \
            -ldlib.19.4.99

