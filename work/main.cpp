#include "custom_draw.h"
#include "vertex_parser.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    custom_draw w;

//    w.resize(1200, 900);
//    w.show();

    QVector<QVector<float>> v;
    vertex_parser(v, "coord.txt");



    return a.exec();
}
