#include "custom_draw.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    custom_draw w;

    w.resize(1200, 900);
    w.show();



    return a.exec();
}
