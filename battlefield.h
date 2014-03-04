#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QCoreApplication>
#include <QSet>
#include "character.h"

class Character;

class Battlefield : public QCoreApplication
{
public:
    Battlefield(int argc, char *argv[]);
    ~Battlefield();

    inline void addCharacter(Character* character){_characters<<character;}
    inline void removeCharacter(Character* character){_characters.remove(character);}

private:
    QSet<Character*> _characters;
};

#endif // BATTLEFIELD_H
