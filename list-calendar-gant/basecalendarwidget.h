#ifndef BASECALENDARWIDGET_H
#define BASECALENDARWIDGET_H

#include <QCalendarWidget>

class BaseCalendarWidget : public QCalendarWidget
{
    Q_OBJECT
public:
    explicit BaseCalendarWidget(QWidget *parent = nullptr);
    ~BaseCalendarWidget();

protected:
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;

private:
    //void initUI();
    //void initSetting();
};

#endif // BASECALENDARWIDGET_H
