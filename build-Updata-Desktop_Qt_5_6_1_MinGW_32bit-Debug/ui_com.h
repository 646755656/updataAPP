/********************************************************************************
** Form generated from reading UI file 'com.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COM_H
#define UI_COM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_com
{
public:
    QLabel *label;

    void setupUi(QDialog *com)
    {
        if (com->objectName().isEmpty())
            com->setObjectName(QStringLiteral("com"));
        com->resize(79, 114);
        label = new QLabel(com);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 54, 12));

        retranslateUi(com);

        QMetaObject::connectSlotsByName(com);
    } // setupUi

    void retranslateUi(QDialog *com)
    {
        com->setWindowTitle(QApplication::translate("com", "Dialog", 0));
        label->setText(QApplication::translate("com", "COM2\346\230\276\347\244\272", 0));
    } // retranslateUi

};

namespace Ui {
    class com: public Ui_com {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COM_H
