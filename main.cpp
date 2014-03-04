#include <iostream>

#include <QCoreApplication>

#include "battlefield.h"
#include "attack.h"
#include "character.h"
#include "part.h"
#include "weapon.h"

using namespace std;

int main(int argc, char *argv[])
{
    Battlefield* battle = new Battlefield(argc, argv);

    Attack* attack = new Attack("Attaque par défaut", 10, 10);
    Part* body1 = new Part("Corps");
    Part* body2 = new Part("Corps");
    Weapon* weapon = new Weapon("Arme", attack);
    Character* character1 = new Character("Perso1", body1, weapon, battle);
    Character* character2 = new Character("Perso2", body2, weapon, battle);
    battle->addCharacter(character1);
    battle->addCharacter(character2);

//  battle->exec();
    while(battle!=NULL)
    {
        cout << "toto" << endl;
        character1->giveAttack(attack, character2);
        cout<<battle<<endl;
        cout<<character1->getName().toStdString()<<" has attacked "<<character2->getName().toStdString()<<" who has "<<character2->getBody()->getHp()<<" left."<<endl;
        character2->giveAttack(attack, character1);
        cout<<character2->getName().toStdString()<<" has attacked "<<character1->getName().toStdString()<<" who has "<<character1->getBody()->getHp()<<" left."<<endl;
    }



    delete character1;
    delete character2;
    delete weapon;
    delete body1;
    delete body2;
    delete attack;
    delete battle;

    return 0;
}
