#include <QApplication>

#include "glcube.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GLCube w;

    w.resize(500, 600);
    w.show();

    return a.exec();
}
