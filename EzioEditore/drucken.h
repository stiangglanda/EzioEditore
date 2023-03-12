#ifndef DRUCKEN_H
#define DRUCKEN_H

#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QPen>

class Drucken
{
    QString text;
    QPrinter* printer;

public:
    Drucken();
    Drucken(QString);
    QString print(QString, bool=false);
    ~Drucken();
};

#endif // DRUCKEN_H
