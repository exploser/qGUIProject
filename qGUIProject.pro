#-------------------------------------------------
#
# Project created by QtCreator 2015-11-07T03:06:35
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qGUIProject

TEMPLATE = app

SOURCES +=      main.cpp \
                PixmapDisplay.cpp \
                QGuiProject.cpp \
                VideoWindowThread.cpp \

HEADERS  +=     PixmapDisplay.h \
                QGuiProject.h \
                VideoWindowThread.h \

FORMS += \
    qguiproject.ui \
    VideoWindow.ui

DISTFILES += \
    LICENSE


OPENCV_DIR = $$clean_path($$(OPENCV_PATH))

CONFIG(release, debug|release): LIBS += -L$$OPENCV_DIR/build/x64/vc12/lib/\
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_features2d \
    -lopencv_calib3d \
    -lopencv_videoio \

else:win32:CONFIG(debug, debug|release): LIBS += -L$$OPENCV_DIR/build/x64/vc12/lib/ \
    -lopencv_cored \
    -lopencv_highguid \
    -lopencv_imgprocd \
    -lopencv_features2dd \
    -lopencv_calib3dd \
    -lopencv_videoiod \

INCLUDEPATH += $$OPENCV_DIR/build/include
DEPENDPATH += $$OPENCV_DIR/build/include

debug {
    DESTDIR     = $$OUT_PWD/debug
    OBJECTS_DIR = $$OUT_PWD/debug/.obj
    UI_DIR      = $$OUT_PWD/debug/.generated/ui
    RCC_DIR     = $$OUT_PWD/debug/.generated
    MOC_DIR     = $$OUT_PWD/debug/.generated/moc
}

release
{
    DESTDIR     = $$OUT_PWD/release
    OBJECTS_DIR = $$OUT_PWD/release/.obj
    UI_DIR      = $$OUT_PWD/release/.generated/ui
    RCC_DIR     = $$OUT_PWD/release/.generated
    MOC_DIR     = $$OUT_PWD/release/.generated/moc
}
