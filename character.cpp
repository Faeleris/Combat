#include "character.h"

//CONSTRUCTORS & DESTRUCTOR

Character::Character() : QObject(), _name("DefCharacter")
{
    connect(_body, SIGNAL(partDestroyed()), this, SLOT(die()));
}

Character::Character(QString name) : QObject(), _name(name)
{
    connect(_body, SIGNAL(partDestroyed()), this, SLOT(die()));
}

Character::Character(QString name, Part* body) : QObject(), _name(name), _body(body)
{
    connect(_body, SIGNAL(partDestroyed()), this, SLOT(die()));
}

Character::Character(QString name, Part* body, Weapon* weapon) :
    QObject(), _name(name), _body(body), _weapon(weapon)
{
    connect(_body, SIGNAL(partDestroyed()), this, SLOT(die()));
}

Character::Character(QString name, Part *body, Weapon *weapon, Battlefield *battlefield) :
    QObject(), _name(name), _body(body), _weapon(weapon), _battlefield(battlefield)
{
    connect(_body, SIGNAL(partDestroyed()), this, SLOT(die()));
}

Character::~Character()
{
    delete _body;
    delete _weapon;
}




//SLOTS

void Character::die()
{
    delete _battlefield;
}


//METHODS

//Initialisation
void Character::setBody(Part *body)
{
    _body = body;
    _attacks.unite(body->getAttacks());
}

void Character::setWeapon(Weapon *weapon)
{
    _weapon = weapon;
    _attacks.unite(weapon->getAttacks());
}

//Other
void Character::recieveAttack(int damage)
{
    _body->takeDamage(damage);
}

void Character::giveAttack(Attack* attack, Character* target)
{
    target->recieveAttack(attack->getStrength());
}
