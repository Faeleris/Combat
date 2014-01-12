#include "attack.h"

Attack::Attack() : _name("DefAttack"), _strength(0), _reach(0)
{}

Attack::Attack(QString name) : _name(name)
{}

Attack::Attack(QString name, int strength) : _name(name), _strength(strength)
{}

Attack::Attack(QString name, int strength, int reach) : _name(name), _strength(strength), _reach(reach)
{}
