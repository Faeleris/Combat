#include "weapon.h"

Weapon::Weapon() : _name("DefWeapon")
{}

Weapon::Weapon(QString name) : _name(name)
{}

Weapon::Weapon(QString name, QSet<Attack*> attacks) : _name(name), _attacks(attacks)
{}

Weapon::~Weapon()
{}
