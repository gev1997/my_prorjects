#include <GL/gl.h>
#include <GL/glut.h>
#include "glm/vec3.hpp"

void displayMe(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);

    glColor3f(0.1, 0.2, 0.8);


    glVertex3f(0, 0, 0);
    glVertex3f(0, 0.5, 0);
    glVertex3f(0.5, 0.5, 0);
    glVertex3f(0.5, 0, 0);

    glVertex3f(0.6, 0.6, 0);
    glVertex3f(0.8, 0.8, 0);

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowSize(400, 300);
    glutInitWindowPosition(500, 500);
    glutCreateWindow("Hello world!");

    glutDisplayFunc(displayMe);

    glutMainLoop();
    return 0;
}
g++ main.cpp -lglut -lGLU -lGL && ./a.out
