#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QTableWidgetItem>

#include "basecalendarwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int rowCount;
    int maxid;

private slots:
    void on_pushButton_add_clicked();

    void on_list_tabBarClicked(int index);

    void on_list_currentChanged(int index);

    void flushList();

    void flushCalendar();

    //void on_calendarWidget_selectionChanged();

    void on_pushButton_cancel_clicked();

    void rowCountFLush();

    //void on_tableWidget_itemChanged(QTableWidgetItem *item);

    void on_pushButton_del_clicked();

    void on_pushButton_del_2_clicked();

    void del(int id);

private:
    Ui::MainWindow *ui;
    QSqlDatabase database;
    BaseCalendarWidget * bc;
};
#endif // MAINWINDOW_H
