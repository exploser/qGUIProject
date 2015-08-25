/********************************************************************************
** Form generated from reading UI file 'VideoWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWINDOW_H
#define UI_VIDEOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "pixmapdisplay.h"

QT_BEGIN_NAMESPACE

class Ui_VideoWindowFormClass
{
public:
    QGridLayout *gridLayout;
    PixmapDisplay *vidLabel;

    void setupUi(QWidget *VideoWindowFormClass)
    {
        if (VideoWindowFormClass->objectName().isEmpty())
            VideoWindowFormClass->setObjectName(QStringLiteral("VideoWindowFormClass"));
        VideoWindowFormClass->resize(451, 300);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VideoWindowFormClass->sizePolicy().hasHeightForWidth());
        VideoWindowFormClass->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(VideoWindowFormClass);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        vidLabel = new PixmapDisplay(VideoWindowFormClass);
        vidLabel->setObjectName(QStringLiteral("vidLabel"));

        gridLayout->addWidget(vidLabel, 0, 0, 1, 1);


        retranslateUi(VideoWindowFormClass);

        QMetaObject::connectSlotsByName(VideoWindowFormClass);
    } // setupUi

    void retranslateUi(QWidget *VideoWindowFormClass)
    {
        VideoWindowFormClass->setWindowTitle(QApplication::translate("VideoWindowFormClass", "Form", 0));
        vidLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoWindowFormClass: public Ui_VideoWindowFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWINDOW_H
