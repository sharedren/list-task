#include "basecalendarwidget.h"

#include <QPainter>
#include <QDebug>
#include <QSqlRecord>
#include <QDateTime>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

BaseCalendarWidget::BaseCalendarWidget(QWidget *parent)
{

}

BaseCalendarWidget::~BaseCalendarWidget()
{

}

/* 需要根据自己的业务逻辑处理当前日期绘制的逻辑 */
void BaseCalendarWidget::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    QCalendarWidget::paintCell(painter, rect, date);

    //painter->save();
    //painter->setRenderHint(QPainter::Antialiasing);

    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM student");
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    }
    else
    {
        while(sqlQuery.next())
        {
            QString name = sqlQuery.value(1).toString();
            QString description = sqlQuery.value(2).toString();
            QString t1 = sqlQuery.value(3).toString();
            QString t2 = sqlQuery.value(4).toString();

            QString currentData = date.toString("yyyy/MM/dd");

             if (t2 == currentData) {
                /* 绘制背景*/
                painter->setPen(Qt::NoPen);
                painter->setBrush(QColor(255, 0, 0));
                painter->drawRoundedRect(rect.x()+1, rect.y()+1, rect.width()-2, rect.height()-2, 3, 3);

                /* 绘制前景*/
                QFont dateFont = painter->font();
                dateFont.setPixelSize(rect.height()-10);
                painter->setFont(dateFont);
                painter->setPen(QColor(255, 255, 255));
                QRect dateRect = QRect(rect.x()+3, rect.y()+3, rect.width()-6, rect.height()-6);
                painter->drawText(dateRect, Qt::AlignCenter, QString::number(date.day()));

                //painter->restore();
            }
        }
    }


}
