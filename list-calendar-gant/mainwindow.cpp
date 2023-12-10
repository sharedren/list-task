#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlRecord>
#include <QDateTime>
#include <QMessageBox>
#include "basecalendarwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建 QLabel 控件
    QLabel *label = new QLabel(this);
    // 加载图片文件
    QImage image(":/image/whale.jpg"); // 使用资源路径或实际文件路径
    // 将 QImage 设置为 QLabel 的内容
    label->setPixmap(QPixmap::fromImage(image));
    // 调整 QLabel 大小以适应图像大小
    label->setScaledContents(true);
    // 添加到布局或窗口中显示
    ui->whale_widget->addWidget(label); // 假设使用了布局管理器 layout

    ui->lineEdit_name->clear();
    ui->lineEdit_description->clear();

    QDate date = QDate::currentDate();

    ui->dateEdit_begin->setDate(date);
    ui->dateEdit_end->setDate(date.addDays(1));

    if (QSqlDatabase::contains("qt_sql_default_connection")){
        database = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("MyDataBase.db");
    }

    if (!database.open()) {
        qDebug() << "Error: failed to connect database." << database.lastError();
    } else {
        // 用于执行sql语句的对象
        QSqlQuery sqlQuery;
        // 构建创建数据库的sql语句字符串
        QString createSql = QString("CREATE TABLE IF NOT EXISTS student (\
                                  name TEXT NOT NULL,\
                                  description TEXT NOT NULL,\
                                    t1 TEXT NOT NULL,\
                                    t2 TEXT NOT NULL)");
        sqlQuery.prepare(createSql);

        // 执行sql语句
        if(!sqlQuery.exec()) {
            qDebug() << "Error: Fail to create table. " << sqlQuery.lastError();
        } else {
            qDebug() << "Table created!";

            rowCountFLush();

            flushList();

            bc = new BaseCalendarWidget();
            ui->verticalLayout->addWidget(bc);
            bc->setSelectedDate(QDate::currentDate());
            connect(bc,SIGNAL(selectionChanged()),this,SLOT(flushCalendar()));

            flushCalendar();
        }
    }


}

MainWindow::~MainWindow()
{
    database.close();
    delete ui;
}

void MainWindow::rowCountFLush()
{
    QSqlQuery sqlQuery;
    if (!sqlQuery.exec("SELECT COUNT(*) FROM student")) {
        qDebug() << sqlQuery.lastError();
        return;
    }

    while (sqlQuery.next()) {
        rowCount = sqlQuery.value(0).toInt();
    }
}

void MainWindow::flushCalendar()
{
    ui->tableWidget_2->setColumnWidth(1, 300);
    ui->tableWidget_2->setColumnWidth(1, 680);

    ui->tableWidget_2->setRowCount(rowCount);

    ui->tableWidget_2->clear();

    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM student");
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    }
    else
    {
        int j = 0;
        while(sqlQuery.next())
        {
            //int id = sqlQuery.value(0).toInt();
            QString name = sqlQuery.value(0).toString();
            QString description = sqlQuery.value(1).toString();
            QString t1 = sqlQuery.value(2).toString();
            QString t2 = sqlQuery.value(3).toString();

            //QString endData = date.toString("yyyy/MM/dd");

            //QString currentData = QDateTime::currentDateTime().toString("yyyy/MM/dd");

            QString currentData = bc->selectedDate().toString("yyyy/MM/dd");

            if (t2 == currentData) {
                //qDebug()<< "++++22+" << t2 << currentData; //获取选中的年月日
                ui->tableWidget_2->setItem(j,0, new QTableWidgetItem(QString("%2").arg(name)));
                ui->tableWidget_2->setItem(j,1, new QTableWidgetItem(QString("%3").arg(description)));
                j++;
            }
        }
        ui->tableWidget_2->setRowCount(j);
    }
}

void MainWindow::flushList()
{
    ui->tableWidget->setColumnWidth(1, 300);
    ui->tableWidget->setColumnWidth(1, 830);

    ui->tableWidget->setRowCount(rowCount);

    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM student");
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    }
    else
    {
        int i = 0;
        while(sqlQuery.next())
        {
            //int id = sqlQuery.value(0).toInt();
            QString name = sqlQuery.value(0).toString();
            QString description = sqlQuery.value(1).toString();
            QString t1 = sqlQuery.value(2).toString();
            QString t2 = sqlQuery.value(3).toString().trimmed();

            //qDebug()<<QString("name:%1 description:%2 t1:%3 t2:%4").arg(name).arg(description).arg(t1).arg(t2);

            //ui->tableWidget->setItem(id,0, new QTableWidgetItem(QString("%1").arg(id)));
            ui->tableWidget->setItem(i,0, new QTableWidgetItem(QString("%2").arg(name)));
            ui->tableWidget->setItem(i,1, new QTableWidgetItem(QString("%3").arg(description)));
            ui->tableWidget->setItem(i,2, new QTableWidgetItem(QString("%4").arg(t1)));
            ui->tableWidget->setItem(i,3, new QTableWidgetItem(QString("%5").arg(t2)));

            //QString endData = date.toString("yyyy/MM/dd");
            QString currentData = QDateTime::currentDateTime().toString("yyyy/MM/dd");


            if (t2 == currentData) {
                ui->tableWidget->item(i, 0)->setBackground(Qt::green);
                ui->tableWidget->item(i, 1)->setBackground(Qt::green);
                ui->tableWidget->item(i, 2)->setBackground(Qt::green);
                ui->tableWidget->item(i, 3)->setBackground(Qt::green);
                ui->tableWidget->item(i, 3)->setForeground(Qt::black);
            } else if (t2 < currentData) { // timeout
                qDebug() << "1111111111111";
                qDebug() << "t2:" << t2 << "current:" << currentData << endl;

                ui->tableWidget->item(i, 3)->setBackground(Qt::red);
                ui->tableWidget->item(i, 3)->setForeground(Qt::white);
            } else { // Time is approaching, one day left
                qDebug() << "222222222222222";
                qDebug() << "t2:" << t2 << "current:" << currentData << endl;

                QDateTime endDate = QDateTime::fromString(t2, "yyyy/MM/dd");
                int daysDiff = QDateTime::currentDateTime().daysTo(endDate); // 计算时间差（天）
                if (daysDiff == 1) {
                    ui->tableWidget->item(i, 3)->setBackground(Qt::yellow);
                    ui->tableWidget->item(i, 3)->setForeground(Qt::black);
                }
            }            
            i++;
        }
    }


}


void MainWindow::on_pushButton_add_clicked()
{
    QSqlQuery sqlQuery;
    char info[256] = {0};

    if (ui->lineEdit_name->text().length() == 0){
        //QMessageBox::information(this,"","empty");
        ui->label_5->setText("name empty");
        return;
    }

    sqlQuery.prepare("INSERT INTO student VALUES(:name,:description,:t1,:t2)");
    sqlQuery.bindValue(":name", ui->lineEdit_name->text());
    sqlQuery.bindValue(":description", ui->lineEdit_description->toPlainText());
    sqlQuery.bindValue(":t1", ui->dateEdit_begin->text());
    sqlQuery.bindValue(":t2", ui->dateEdit_end->text());

    qDebug() << "end:" << ui->dateEdit_end->text() << "begin:" << ui->dateEdit_begin->text();
    if (ui->dateEdit_end->text() < ui->dateEdit_begin->text()){
        //QMessageBox::information(this,"","time error");
        ui->label_5->setText("time illegal");
        return;
    }

    if(!sqlQuery.exec()) {
        qDebug() << "Error: Fail to insert data. " << sqlQuery.lastError();
        //sprintf(info, "%s", sqlQuery.lastError().text());
        //QMessageBox::information(this,"","sql Fail");
        ui->label_5->setText("sql failed");
    } else {
        //QMessageBox::information(this,"","success");
        ui->label_5->setText("success");
    }

    rowCountFLush();
}

void MainWindow::on_list_tabBarClicked(int index)
{
    flushList();
    flushCalendar();
}

// 废弃函数
#if 0
void MainWindow::on_pushButton_remove_clicked()
{

    while(ui->tableWidget->selectedItems().count() > 0){
        int rowIdx = ui->tableWidget->selectedItems()[0]->row();
        ui->tableWidget->removeRow(rowIdx);
    }

    QSqlQuery sqlQuery;

    sqlQuery.exec(QString("DELETE FROM student WHERE id = %1").arg(id));
    if(!sqlQuery.exec())
    {
        qDebug()<<sqlQuery.lastError();
    }
    else
    {
        qDebug()<<"deleted data success!";
    }

}
#endif

void MainWindow::on_list_currentChanged(int index)
{
   flushList();
   flushCalendar();
}
/*
void MainWindow::on_calendarWidget_selectionChanged()
{
    qDebug()<<ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"); //获取选中的年月日
    flushCalendar();
}
*/
void MainWindow::on_pushButton_cancel_clicked()
{
    ui->lineEdit_name->clear();
    ui->lineEdit_description->clear();
    ui->dateEdit_begin->setDate(QDate::currentDate());
    ui->dateEdit_end->setDate(QDate::currentDate());
}
