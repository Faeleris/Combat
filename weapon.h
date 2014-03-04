#ifndef WEAPON_H
#define WEAPON_H

#include <QCoreApplication>
#include <QString>
#include <QSet>

#include "attack.h"

class Weapon
{
public:
    Weapon();
    Weapon(QString name);
    Weapon(QString name, Attack* attack);
    Weapon(QString name, QSet<Attack*> attacks);

    ~Weapon();

    inline void setName(QString name){_name = name;}
    inline void addAttack(Attack* attack){_attacks<<attack;}
    inline void removeAttack(Attack* attack){_attacks.remove(attack);}

    inline QString getName(){return _name;}
    inline QSet<Attack*> getAttacks(){return _attacks;}

private:
    QString _name;
    QSet<Attack*> _attacks;
};

#endif // WEAPON_H
