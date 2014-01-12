#include "character.h"

Character::Character() : _name("DefCharacter")
{

}

Character::Character(QString name) : _name(name)
{}

Character::Character(QString name, Part* body) : _name(name), _body(body)
{}

Character::Character(QString name, Part* body, Weapon* weapon) :
    _name(name), _body(body), _weapon(weapon)
{}

Character::~Character()
{}
