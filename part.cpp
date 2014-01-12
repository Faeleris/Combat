#include "part.h"

Part::Part() : QObject(), _name("DefPart"), _hp(100)
{}

Part::Part(QString name) : QObject(), _name(name), _hp(100)
{}

Part::Part(QString name, QSet<Part*> connections) :
    QObject(), _name(name), _hp(100), _connections(connections)
{}

Part::Part(QString name, QSet<Part*> connections, QSet<Attack*> attacks) :
    QObject(), _name(name), _hp(100), _connections(connections), _attacks(attacks)
{}

Part::~Part()
{}



void Part::takeDamage(int damage)
{
    if (_hp > damage)
    {
        _hp-=damage;
    }
    else
    {
        _hp = 0;
        emit partDestroyed();
    }
}
