#ifndef ATTACK_H
#define ATTACK_H

#include <QCoreApplication>
#include <QString>

class Attack
{
public:
    Attack();
    Attack(QString name);
    Attack(QString name, int strength);
    Attack(QString name, int strength, int reach);
    ~Attack();

    inline void setName(QString name){_name = name;}
    inline void setStrength(int strength){_strength = strength;}
    inline void setReach(int reach){_reach = reach;}

    inline QString getName()const{return _name;}
    inline int getStrength()const{return _strength;}
    inline int getReach()const{return _reach;}

private:
    QString _name;
    int _strength;
    int _reach;
};

#endif // ATTACK_H
