#ifndef MYCASE_H
#define MYCASE_H

#include <QObject>
#include <QList>

class MyCase : public QObject
{
    Q_OBJECT
public:
    explicit MyCase(QObject *parent = nullptr);
    Q_PROPERTY(QString ValueQML READ readValue NOTIFY valueChanged)
    QString readValue();
    MyCase& operator=(const MyCase &myCase);
    void setValue(int value);
    void ChangeColor();
    int getValue();
signals:
    void valueChanged();
private:
    int val;
};

#endif // MYCASE_H
