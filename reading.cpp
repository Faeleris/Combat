#include "reading.h"

/*Reads a .bdy (body) file and returns a Part object pointer destined
 *to become the _body attribute of a Character object*/
Part* readBody(QString fileName)
{
    QFile file(fileName);   //Open file
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))   //Test correct opening
        return/*???*/;
    QTextStream in(&file);  //Copy file in memory

    QStringList data = in.readAll().split("\n");    //Extract all the file in a table, each line, corresponding to a part, being one entry
    QString root = data[0];   //Take first line, since its content will become _body in the associated Character object
    Part* body = readPart(root, data);  //Initiate recursive reading of Parts from the file

    return body;
}

/*Creates a Part object pointer, including its connections, then returns it*/
Part* readPart(QString line, QStringList data, Part* root)
{
    Part* part;
    QStringList infos = line.split("|");    //The "|" symbol has been chosen to be the separator between part characteristics groups
    QStringList characteristics = infos[0].split(";");  //The ";" symbol has been chosen to be the separator between individual characteristics ; this line separates primary attributes
    QStringList connections = infos[1].split(";");  //See previous comment ; this line separates connections

    part->setName(characteristics[0]);  //Sets the part _name (first primary attribute)
    part->setHp(characteristics[1].toInt());    //Sets the part _hp (second primary attribute)

    for(i = 0 ; i < connections.size() ; i++)   //For each existing connection
    {
        if(connections[i] != root->getName())   //Test if the connection isn't the root, using its name
        {
            QString newLine = findLine(connections[i], data);   //Find which line describes the connected part
            part->addConnection(readPart(newLine, data, part)); //Recursive call for the found part
        }
        else
            part->addConnection(root);  //If the tested connection is the already known root, add it
    }

    return part; //Return the completly described Part
}

/*Finds the line describing a part from its name*/
QString findLine(QString connection, QStringList data)
{
    for(i = 0 ; i < data.size() ; i++)  //For each line
    {
        if(data[i].indexOf(connection) == 0)    //If the line begins by the name of the researched part (meaning the line describes the part)
            return data[i]; //Return the line
    }
    return /*???*/;
}
