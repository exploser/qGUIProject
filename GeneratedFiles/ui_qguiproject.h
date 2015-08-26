/********************************************************************************
** Form generated from reading UI file 'qguiproject.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGUIPROJECT_H
#define UI_QGUIPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qGUIProjectClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *btnShowVids;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbAlter1;
    QRadioButton *rbAlter2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rbFramework1;
    QRadioButton *rbFramework2;
    QPushButton *btnTerminate;

    void setupUi(QMainWindow *qGUIProjectClass)
    {
        if (qGUIProjectClass->objectName().isEmpty())
            qGUIProjectClass->setObjectName(QStringLiteral("qGUIProjectClass"));
        qGUIProjectClass->resize(302, 188);
        centralWidget = new QWidget(qGUIProjectClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnShowVids = new QPushButton(centralWidget);
        btnShowVids->setObjectName(QStringLiteral("btnShowVids"));

        gridLayout->addWidget(btnShowVids, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        rbAlter1 = new QRadioButton(groupBox);
        rbAlter1->setObjectName(QStringLiteral("rbAlter1"));
        rbAlter1->setChecked(true);

        verticalLayout->addWidget(rbAlter1);

        rbAlter2 = new QRadioButton(groupBox);
        rbAlter2->setObjectName(QStringLiteral("rbAlter2"));

        verticalLayout->addWidget(rbAlter2);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        rbFramework1 = new QRadioButton(groupBox_2);
        rbFramework1->setObjectName(QStringLiteral("rbFramework1"));
        rbFramework1->setChecked(true);

        verticalLayout_2->addWidget(rbFramework1);

        rbFramework2 = new QRadioButton(groupBox_2);
        rbFramework2->setObjectName(QStringLiteral("rbFramework2"));
        rbFramework2->setEnabled(true);
        rbFramework2->setCheckable(true);

        verticalLayout_2->addWidget(rbFramework2);


        gridLayout->addWidget(groupBox_2, 1, 1, 1, 1);

        btnTerminate = new QPushButton(centralWidget);
        btnTerminate->setObjectName(QStringLiteral("btnTerminate"));
        btnTerminate->setEnabled(false);

        gridLayout->addWidget(btnTerminate, 0, 1, 1, 1);

        qGUIProjectClass->setCentralWidget(centralWidget);

        retranslateUi(qGUIProjectClass);

        QMetaObject::connectSlotsByName(qGUIProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *qGUIProjectClass)
    {
        qGUIProjectClass->setWindowTitle(QApplication::translate("qGUIProjectClass", "QThreaded Video Display", 0));
        btnShowVids->setText(QApplication::translate("qGUIProjectClass", "Start", 0));
        groupBox->setTitle(QApplication::translate("qGUIProjectClass", "Alteration", 0));
        rbAlter1->setText(QApplication::translate("qGUIProjectClass", "High FPS Window", 0));
        rbAlter2->setText(QApplication::translate("qGUIProjectClass", "Low FPS Window", 0));
        groupBox_2->setTitle(QApplication::translate("qGUIProjectClass", "Drawing Framework", 0));
        rbFramework1->setText(QApplication::translate("qGUIProjectClass", "OpenCV", 0));
        rbFramework2->setText(QApplication::translate("qGUIProjectClass", "QT", 0));
        btnTerminate->setText(QApplication::translate("qGUIProjectClass", "Terminate", 0));
    } // retranslateUi

};

namespace Ui {
    class qGUIProjectClass: public Ui_qGUIProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGUIPROJECT_H
