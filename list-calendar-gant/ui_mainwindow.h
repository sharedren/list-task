/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *list;
    QWidget *tab_add;
    QPushButton *pushButton_add;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_name;
    QPushButton *pushButton_cancel;
    QTextEdit *lineEdit_description;
    QCalendarWidget *calendarWidget_2;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *whale_widget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *dateEdit_begin;
    QLabel *label_4;
    QDateEdit *dateEdit_end;
    QWidget *tab_list;
    QTableWidget *tableWidget;
    QPushButton *pushButton_del;
    QLabel *label_6;
    QWidget *tab_calendar;
    QTableWidget *tableWidget_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_del_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 810);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        list = new QTabWidget(centralwidget);
        list->setObjectName(QString::fromUtf8("list"));
        tab_add = new QWidget();
        tab_add->setObjectName(QString::fromUtf8("tab_add"));
        pushButton_add = new QPushButton(tab_add);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(110, 370, 93, 28));
        label = new QLabel(tab_add);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 110, 72, 15));
        label_2 = new QLabel(tab_add);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 160, 72, 15));
        lineEdit_name = new QLineEdit(tab_add);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(200, 110, 561, 21));
        pushButton_cancel = new QPushButton(tab_add);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(230, 370, 93, 28));
        lineEdit_description = new QTextEdit(tab_add);
        lineEdit_description->setObjectName(QString::fromUtf8("lineEdit_description"));
        lineEdit_description->setGeometry(QRect(200, 160, 561, 141));
        calendarWidget_2 = new QCalendarWidget(tab_add);
        calendarWidget_2->setObjectName(QString::fromUtf8("calendarWidget_2"));
        calendarWidget_2->setGeometry(QRect(830, 90, 296, 218));
        label_5 = new QLabel(tab_add);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 407, 210, 21));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(61, 123, 185);"));
        verticalLayoutWidget_2 = new QWidget(tab_add);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(540, 400, 631, 271));
        whale_widget = new QVBoxLayout(verticalLayoutWidget_2);
        whale_widget->setObjectName(QString::fromUtf8("whale_widget"));
        whale_widget->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(tab_add);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 320, 364, 23));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        dateEdit_begin = new QDateEdit(layoutWidget);
        dateEdit_begin->setObjectName(QString::fromUtf8("dateEdit_begin"));
        dateEdit_begin->setDateTime(QDateTime(QDate(2023, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_3->addWidget(dateEdit_begin);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        dateEdit_end = new QDateEdit(layoutWidget);
        dateEdit_end->setObjectName(QString::fromUtf8("dateEdit_end"));
        dateEdit_end->setDateTime(QDateTime(QDate(2023, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_3->addWidget(dateEdit_end);

        list->addTab(tab_add, QString());
        tab_list = new QWidget();
        tab_list->setObjectName(QString::fromUtf8("tab_list"));
        tableWidget = new QTableWidget(tab_list);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 1090, 741));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMaximumSize(QSize(1090, 16777215));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->setDragEnabled(false);
        tableWidget->setWordWrap(true);
        tableWidget->setRowCount(1);
        tableWidget->setColumnCount(5);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setHighlightSections(true);
        pushButton_del = new QPushButton(tab_list);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setGeometry(QRect(1130, 50, 93, 28));
        label_6 = new QLabel(tab_list);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1121, 110, 121, 241));
        list->addTab(tab_list, QString());
        tab_calendar = new QWidget();
        tab_calendar->setObjectName(QString::fromUtf8("tab_calendar"));
        tableWidget_2 = new QTableWidget(tab_calendar);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(410, 0, 851, 771));
        tableWidget_2->setRowCount(0);
        tableWidget_2->setColumnCount(3);
        tableWidget_2->horizontalHeader()->setVisible(false);
        tableWidget_2->verticalHeader()->setVisible(false);
        verticalLayoutWidget = new QWidget(tab_calendar);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 60, 291, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_del_2 = new QPushButton(tab_calendar);
        pushButton_del_2->setObjectName(QString::fromUtf8("pushButton_del_2"));
        pushButton_del_2->setGeometry(QRect(140, 330, 93, 28));
        list->addTab(tab_calendar, QString());

        horizontalLayout->addWidget(list);

        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(lineEdit_name, lineEdit_description);
        QWidget::setTabOrder(lineEdit_description, dateEdit_begin);
        QWidget::setTabOrder(dateEdit_begin, dateEdit_end);
        QWidget::setTabOrder(dateEdit_end, pushButton_add);
        QWidget::setTabOrder(pushButton_add, pushButton_cancel);
        QWidget::setTabOrder(pushButton_cancel, tableWidget);
        QWidget::setTabOrder(tableWidget, tableWidget_2);
        QWidget::setTabOrder(tableWidget_2, list);

        retranslateUi(MainWindow);

        list->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "list-task", nullptr));
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\217\217\350\277\260", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210", nullptr));
        label_5->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        dateEdit_begin->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy/MM/dd", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        dateEdit_end->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy/MM/dd", nullptr));
        list->setTabText(list->indexOf(tab_add), QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        pushButton_del->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        label_6->setText(QString());
        list->setTabText(list->indexOf(tab_list), QCoreApplication::translate("MainWindow", "\345\210\227\350\241\250", nullptr));
        pushButton_del_2->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        list->setTabText(list->indexOf(tab_calendar), QCoreApplication::translate("MainWindow", "\346\227\245\345\216\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
