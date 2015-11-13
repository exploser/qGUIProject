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

SOURCES += 	main.cpp \
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

win32:CONFIG(release, debug|release): LIBS += -L$$OPENCV_DIR/build/x64/vc12/lib/\
    -lopencv_core2411 \
    -lopencv_highgui2411 \
    -lopencv_imgproc2411 \
    -lopencv_features2d2411 \
    -lopencv_calib3d2411 \

else:win32:CONFIG(debug, debug|release): LIBS += -L$$OPENCV_DIR/build/x64/vc12/lib/ \
    -lopencv_core2411d \
    -lopencv_highgui2411d \
    -lopencv_imgproc2411d \
    -lopencv_features2d2411d \
    -lopencv_calib3d2411d \

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
