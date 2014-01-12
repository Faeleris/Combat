#ifndef CHARACTER_H
#define CHARACTER_H

#include <QCoreApplication>
#include <QString>

#include "battlefield.h"
#include "part.h"
#include "weapon.h"

class Battlefield;

class Character
{
public:
    Character();
    Character(QString name);
    Character(QString name, Part* body);
    Character(QString name, Part* body, Weapon* weapon);
    ~Character();

    inline void setName(QString name){_name = name;}
    inline void setBody(Part* body){_body = body;}
    inline void setWeapon(Weapon* weapon){_weapon = weapon;}
    inline void setBattlefield(Battlefield* battlefield){_battlefield = battlefield;}
    inline QString getName(){return _name;}
    inline Part* getBody(){return _body;}
    inline Weapon* getWeapon(){return _weapon;}
    inline Battlefield* getBattlefield(){return _battlefield;}

private:
    QString _name;
    Part* _body;
    Weapon* _weapon;
    Battlefield* _battlefield;
};

#endif // CHARACTER_H
