#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

#include <QCoreApplication>
#include <QString>
#include <QSet>

#include "attack.h"
#include "battlefield.h"
#include "part.h"
#include "weapon.h"

class Battlefield;

class Character : public QObject
{
    Q_OBJECT

public:
    Character();
    Character(QString name);
    Character(QString name, Part* body);
    Character(QString name, Part* body, Weapon* weapon);
    Character(QString name, Part *body, Weapon *weapon, Battlefield *battlefield);
    ~Character();

    inline void setName(QString name){_name = name;}
    void setBody(Part* body);
    void setWeapon(Weapon* weapon);
    inline void setBattlefield(Battlefield* battlefield){_battlefield = battlefield;}
    inline void addAttack(Attack* attack){_attacks.insert(attack);}
    inline void removeAttack(Attack* attack){_attacks.remove(attack);}
    inline QString getName(){return _name;}
    inline Part* getBody(){return _body;}
    inline Weapon* getWeapon(){return _weapon;}
    inline Battlefield* getBattlefield(){return _battlefield;}
    inline QSet<Attack*> getAttacks(){return _attacks;}

    void giveAttack(Attack* attack, Character* target);
    void recieveAttack(int damage);

public slots:
    void die();

private:
    QString _name;
    Part* _body;
    Weapon* _weapon;
    Battlefield* _battlefield;
    QSet<Attack*> _attacks;
};

#endif // CHARACTER_H
