/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit_description;
    QPushButton *pushButton_add;
    QDateEdit *dateEdit_end;
    QPushButton *pushButton_cancel;
    QLabel *label;
    QDateEdit *dateEdit_begin;
    QLabel *label_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(778, 596);
        lineEdit_name = new QLineEdit(Dialog);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(170, 80, 561, 21));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 130, 72, 15));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 340, 72, 15));
        lineEdit_description = new QLineEdit(Dialog);
        lineEdit_description->setObjectName(QString::fromUtf8("lineEdit_description"));
        lineEdit_description->setGeometry(QRect(170, 130, 561, 131));
        pushButton_add = new QPushButton(Dialog);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(70, 400, 93, 28));
        dateEdit_end = new QDateEdit(Dialog);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        dateEdit_end->setGeometry(QRect(170, 330, 110, 22));
        dateEdit_end->setDateTime(QDateTime(QDate(2023, 1, 1), QTime(0, 0, 0)));
        pushButton_cancel = new QPushButton(Dialog);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(190, 400, 93, 28));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 80, 72, 15));
        dateEdit_begin = new QDateEdit(Dialog);
        dateEdit_begin->setObjectName(QString::fromUtf8("dateEdit_begin"));
        dateEdit_begin->setGeometry(QRect(170, 290, 110, 22));
        dateEdit_begin->setDateTime(QDateTime(QDate(2023, 1, 1), QTime(0, 0, 0)));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 290, 72, 15));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\346\217\217\350\277\260", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        pushButton_add->setText(QCoreApplication::translate("Dialog", "\346\267\273\345\212\240", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("Dialog", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\344\273\273\345\212\241\345\220\215\347\247\260", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
