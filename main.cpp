#include "midtermui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MidTermUi w;
    w.show();
    return a.exec();
}
