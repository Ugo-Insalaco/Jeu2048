#include "plateau.h"
#include "mycase.h"
#include "iostream"
#include <QDebug>
using namespace std;

Plateau::Plateau(QObject *parent) : QObject(parent)
{
    MyCase myCase;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            grille[i][j] = myCase;
            List.append(grille[i][j].readValue()); // tous sont 0
            Color.append("#d7ccb8");
            freecase[i*4+j] = 1;
        }
    }
    score = 0;
    colorSet[0] = "#d7ccb8";
    colorSet[2] = "#f8eeb5";
    colorSet[4] = "#f4794f";
    colorSet[8] = "#f54545";
    colorSet[16] = "#ebd465";
    colorSet[32] = "#4a86e8";
    colorSet[64] = "#4ad8e8";
    colorSet[128] = "#4a86e8";
    colorSet[256] = "#9a076b";
    colorSet[512] = "#d9154f";
    colorSet[1024] = "#cf123b";
    colorSet[2048] = "#ff0000";
    Gamecheck = "true";
    emit gamecheckChanged();

}

void Plateau::InitJeu()
{
    srand((unsigned)time(NULL));
    int pos = rand() % 16; // fournir une position(0~15) aléatoirement
    grille[pos/4][pos%4].setValue(2);
    freecase[pos]=0;
    score=0;
    Update();
}

void Plateau::restart(){
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            grille[i][j].setValue(0);
            List[4*i+j]=QString::number(0);
            freecase[4*i+j]=1;
        }
    }
    srand((unsigned)time(NULL));
    int pos = rand() % 16; // fournir une position(0~15) aléatoirement
    grille[pos/4][pos%4].setValue(2);      // la valeur initiale est 2
    freecase[pos]=0;
    score = 0;
    Gamecheck = "true";
    NewCase();

    emit valueChanged();
}
void Plateau::NewCase()
{
    srand((unsigned)time(NULL));   // fournir une position aléatoirement parmis les cases disponibles
    int nbFree = 0;
    for(int i =0; i< 16;i++){
        if(freecase[i]==1)
            nbFree++;
    }
    int ind = rand() % nbFree + 1;
    int compt = 0;
    int pos = 0;
    for(int i=0; i< 16; i++){
        if(compt < ind && freecase[i]==1){
            compt++;
            pos=i;
        }
    }
    int alea = rand()%5+1;
    if(alea>4){
        grille[pos/4][pos%4].setValue(4);
    }
    else{
        grille[pos/4][pos%4].setValue(2);
    }
    Update();
}

bool Plateau::noAdd()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if((grille[i][j].getValue()==grille[i+1][j].getValue()) ||
                    (grille[i][j].getValue()==grille[i][j+1].getValue()))
                return false;
        }
    return true;
}

void Plateau::up()
{
    bool moved=false;  //判断是否有格子动了，没动就不能产生新格子
        for(int i=0;i<4;i++) // bouger
            for(int j=0;j<4;j++)
            {
                int val = grille[i][j].getValue();
                if (val!=0)
                {
                    int pos = i;
                    while (grille[pos-1][j].getValue()==0 && pos>0) {
                        grille[pos][j].setValue(0);
                        grille[pos-1][j].setValue(val);
                        pos -= 1;
                        moved = true;
                    }
                }
            }
        for(int i=0;i<3;i++)    // add
            for(int j=0;j<4;j++)
            {
                int val = grille[i][j].getValue();
                if (val!=0)
                {
                    if(grille[i+1][j].getValue()==val)
                    {
                        grille[i][j].setValue(2*val);
                        grille[i+1][j].setValue(0);
                        score+=val;
                        moved=true;
                    }
                 }
            }
        for(int i=0;i<4;i++) // rebouger
            for(int j=0;j<4;j++)
            {
                int val = grille[i][j].getValue();
                if (val!=0)
                {
                    int pos = i;
                    while (grille[pos-1][j].getValue()==0 && pos>0) {
                        grille[pos][j].setValue(0);
                        grille[pos-1][j].setValue(val);
                        pos -= 1;
                    }
                }
            }
        Update();
        if(moved)
            NewCase();

}

void Plateau::down()
{
    bool moved=false;  //判断是否有格子动了，没动就不能产生新格子

        for(int i=3;i>=0;i--)
            for(int j=3;j>=0;j--)
            {
                int val = grille[i][j].getValue();
                if (val!=0)
                {
                    int pos = i;
                    while (grille[pos+1][j].getValue()==0 && pos<3) {
                        grille[pos][j].setValue(0);
                        grille[pos+1][j].setValue(val);
                        pos += 1;
                        moved = true;
                    }                   
                }
            }
        for(int i=3;i>0;i--)    // add
            for(int j=3;j>=0;j--)
            {
                int val = grille[i][j].getValue();
                if (val!=0)
                {
                    if(grille[i-1][j].getValue()==val)
                    {
                        grille[i][j].setValue(2*val);
                        grille[i-1][j].setValue(0);
                        score+=val;
                        moved = true;
                    }
                }
            }
        for(int i=3;i>=0;i--)
            for(int j=3;j>=0;j--)
            {
                int val = grille[i][j].getValue();
                if (val!=0)
                {
                    int pos = i;
                    while (grille[pos+1][j].getValue()==0 && pos<3) {
                        grille[pos][j].setValue(0);
                        grille[pos+1][j].setValue(val);
                        pos += 1;
                    }
                }
            }
        Update();
        if(moved)
            NewCase();

}

void Plateau::left()
{
    bool moved=false;  //判断是否有格子动了，没动就不能产生新格子

        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                int val = grille[i][j].getValue();
                if (val!=0)
                {
                    int pos = j;
                    while (grille[i][pos-1].getValue()==0 && pos>0) {
                        grille[i][pos].setValue(0);
                        grille[i][pos-1].setValue(val);
                        pos -= 1;
                        moved = true;
                    }                    
                }
            }
        for(int i=0;i<4;i++)    // add
            for(int j=0;j<3;j++)
            {
                int val = grille[i][j].getValue();
                if (val!=0)
                {
                    if(grille[i][j+1].getValue()==val)
                    {
                        grille[i][j].setValue(2*val);
                        grille[i][j+1].setValue(0);
                        score+=val;
                        moved = true;
                    }
                 }
            }
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                int val = grille[i][j].getValue();
                if (val!=0)
                {
                    int pos = j;
                    while (grille[i][pos-1].getValue()==0 && pos>0) {
                        grille[i][pos].setValue(0);
                        grille[i][pos-1].setValue(val);
                        pos -= 1;
                    }
                }
            }
        Update();
        if(moved)
            NewCase();

}

void Plateau::right()
{
    bool moved=false;  //判断是否有格子动了，没动就不能产生新格子

        for(int i=3;i>=0;i--)
            for(int j=3;j>=0;j--)
            {
                int val = grille[i][j].getValue();
                if (val!=0)
                {
                    int pos = j;
                     while (grille[i][pos+1].getValue()==0 && pos<3) {
                        grille[i][pos].setValue(0);
                        grille[i][pos+1].setValue(val);
                        pos += 1;
                        moved = true;
                    }

                }
            }

        for(int i=3;i>=0;i--)    // add
            for(int j=3;j>0;j--)
            {
                int val = grille[i][j].getValue();
                if (val!=0)
                {
                    if(grille[i][j-1].getValue()==val)
                    {
                        grille[i][j].setValue(2*val);
                        grille[i][j-1].setValue(0);
                        score+=val;
                        moved = true;
                    }
                }
            }

        for(int i=3;i>=0;i--)
            for(int j=3;j>=0;j--)
            {
                int val = grille[i][j].getValue();
                if (val!=0)
                {
                    int pos = j;
                     while (grille[i][pos+1].getValue()==0 && pos<3) {
                        grille[i][pos].setValue(0);
                        grille[i][pos+1].setValue(val);
                        pos += 1;
                    }

                }
            }

        Update();
        if(moved)
            NewCase();

}

void Plateau::Update()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            int val = grille[i][j].getValue();
            List[i*4+j] = grille[i][j].readValue();
            if(val!=0)
                freecase[i*4+j]=0;
            else
                freecase[i*4+j]=1;
            Color[i*4+j] = QString::fromStdString(colorSet[val]);
        }
    Checkgame();
    emit valueChanged();
    emit colorChanged();
    emit scoreChanged();
}

bool Plateau::Full()
{
    int nbFree = 0;
    for(int i =0; i< 16;i++){
        if(freecase[i]==1)
            nbFree++;
    }
    if (nbFree==0)
        return true;
    else
        return false;
}

void Plateau::Checkgame()
{
    if (Full())
        {
        bool check = false;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if((grille[i][j].getValue()==grille[i+1][j].getValue()) || (grille[i][j].getValue()==grille[i][j+1].getValue()))
                {
                    check= true;
                }
            }
        }
        if(!check){
            Gamecheck="false";
            emit gamecheckChanged();
        }
    }

}

QString Plateau::readScore(){
    return QString::number(score);
}




