#ifndef PLATEAU_H
#define PLATEAU_H

#include <QObject>
#include <string>
#include <vector>
#include "mycase.h"
using namespace std;

class Plateau : public QObject
{
    Q_OBJECT
public:
    explicit Plateau(QObject *parent = nullptr);    
    Q_PROPERTY(QList<QString> ValuesQML MEMBER List NOTIFY valueChanged)
    Q_PROPERTY(QList<QString> ColorQML MEMBER Color NOTIFY colorChanged)
    Q_PROPERTY(QString GamecheckQML MEMBER Gamecheck NOTIFY gamecheckChanged)
    Q_PROPERTY(QString ScoreQML READ readScore NOTIFY scoreChanged)
    void InitJeu();
    void NewCase();
    void Update();
    bool noAdd();
    void Checkgame();
    bool Full();
    Q_INVOKABLE void up();
    Q_INVOKABLE void down();
    Q_INVOKABLE void left();
    Q_INVOKABLE void right();
    Q_INVOKABLE void restart();
    QString readScore();
signals:
    void valueChanged();
    void colorChanged();
    void gamecheckChanged();
    void scoreChanged();
private:
    MyCase grille[4][4];
    QList<QString> List;
    // List: pour lier la position dans grille à la position dans les case
    QList<QString> Color;
    QString Gamecheck;   // si on peut utiliser key_up directement
    int score;
    int freecase[16];
    map<int,string> colorSet; // stocker les couleurs
};

#endif // PLATEAU_H
