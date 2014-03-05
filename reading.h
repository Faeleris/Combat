#ifndef READING_H
#define READING_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>

#include "part.h"


Part* readBody(QString fileName);
Part* readPart(QString line, QStringList data, Part* root = NULL);
QString findLine(QString connection, QStringList data);

#endif // READING_H
