#include "drucken.h"

Drucken::Drucken()
{
}

Drucken::Drucken(QString t) : text{t}
{
}

QString Drucken::print(QString filename, bool cb)
{
    printer = new QPrinter();

    if(cb==true)
    {
        printer->setOutputFormat(QPrinter::PdfFormat);
        printer->setFontEmbeddingEnabled(false);
        printer->setOutputFileName(filename);
    }
    else
    {
        QPrintDialog* dialog = new QPrintDialog(printer);
        dialog->exec();
    }

    QPainter painter;
    painter.begin(printer);
    painter.drawText(100,100,900,900, Qt::AlignTop|Qt::AlignLeft,text);
    painter.end();

    return "Drucken erfolgreich";
}

Drucken::~Drucken()
{
   delete printer;
}
