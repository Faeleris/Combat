#ifndef PART_H
#define PART_H

#include <QCoreApplication>
#include <QObject>
#include <QString>
#include <QSet>

#include "attack.h"

class Part : public QObject
{
    Q_OBJECT

public:
    Part();
    Part(QString name);
    Part(QString name, QSet<Part*> connections);
    Part(QString name, QSet<Part*> connections, QSet<Attack*> attacks);
    ~Part();

    inline void setName(QString name){_name = name;}
    inline void setHp(int hp){_hp = hp;}
    inline void addAttack(Attack* attack){_attacks<<attack;}
    inline void removeAttack(Attack* attack){_attacks.remove(attack);}
    inline void addConnection(Part* part){_connections<<part;}
    inline void removeConnection(Part* part){_connections.remove(part);}
    inline QString getName(){return _name;}
    inline int getHp(){return _hp;}
    inline QSet<Attack*> getAttacks(){return _attacks;}
    inline QSet<Part*> getConnections(){return _connections;}

    void takeDamage(int damage);

signals:
    void partDestroyed();

private:
    QString _name;
    int _hp;
    QSet<Part*> _connections;
    QSet<Attack*> _attacks;
};

#endif // PART_H
