#include <GL/gl.h>
//#include <GL/glew.h>
#include <GL/glut.h>

//#include <glm/glm.hpp>

#include <iostream>

/*
 * character
    glOrtho(0,50,0,50,0,10);
    glRasterPos2i(30, 20);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'G');

 */

float rX = 10;
float rY = 0.0;
float rZ = 0.0;

GLfloat g_vertex_buffer_data[] = {
    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 12*3);
    /*
    glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(rX, 1, 0, 0);
    glRotatef(rY, 0, 1, 0);
    glRotatef(rZ, 0, 0, 1);

    glBegin(GL_LINES);


    glColor3f(1, 0, 0);

    glVertex3f(0,0,0);
    glVertex3f(0.8, 0, 0);

    glVertex3f(0, 0, 0);
    glVertex3f(0, 0.8, 0);

    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 0.8);


    glColor3f(0, 1, 0);

    //
    glVertex3f(0, 0, 0);
    glVertex3f(0.5, 0, 0);

    glVertex3f(0.5, 0, 0);
    glVertex3f(0.5, 0, 0.5);

    glVertex3f(0.5, 0, 0.5);
    glVertex3f(0, 0, 0.5);

    glVertex3f(0, 0, 0.5);
    glVertex3f(0, 0, 0);

    //
    glVertex3f(0, 0.5, 0);
    glVertex3f(0.5, 0.5, 0);

    glVertex3f(0.5, 0.5, 0);
    glVertex3f(0.5, 0.5, 0.5);

    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0, 0.5, 0.5);

    glVertex3f(0, 0.5, 0.5);
    glVertex3f(0, 0.5, 0);


    //
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0.5, 0);

    glVertex3f(0.5, 0, 0);
    glVertex3f(0.5, 0.5, 0);

    glVertex3f(0.5, 0, 0.5);
    glVertex3f(0.5, 0.5, 0.5);

    glVertex3f(0, 0, 0.5);
    glVertex3f(0, 0.5, 0.5);


    glEnd();
    glFlush();
    */
}

void keyPress(int key, int x, int y) {


    glutPostRedisplay();
}

void mouseClickEvent(int key, int state, int x, int y) {
    if (key == 3) {
        if (rX < 0)
            rX = 0;

        rX += 1;
        rY = 0;
        rZ = 0;
    }
    else if (key == 4){
        if (rX > 0)
            rX = 0;

        rX -= 1;
        rY = 0;
        rZ = 0;
    }
    else {
        rX = 0;
    }

    if (rX <= -5 || rX >= 5)
        rX = 0;

    glutPostRedisplay();
}

int lastX = 0;
int lastY = 0;

void mouseMotionEvent(int y, int x) {
    if (x - lastX > 0) {
        if (rX < 0)
            rX = 0;

        //rY = 0;
        rX += 1;
        //rZ = 0;
    }
    else {
        if (rX > 0)
            rX = 0;

        //rY = 0;
        rX -= 1;
        //rZ = 0;
    }

    if (y - lastY > 0) {
        if (rY < 0)
            rY = 0;

        //rX = 0;
        rY += 1;
        //rZ = 0;
    }
    else {
        if (rY > 0)
            rY = 0;

        //rX = 0;
        rY -= 1;
        //rZ = 0;
    }

    if (rY <= -5 || rY >= 5)
        rY = 0;
    if (rX <= -5 || rX >= 5)
        rX = 0;

    lastX = x;
    lastY = y;

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(500, 500);
    glutCreateWindow("Cube");

    glutDisplayFunc(display);

    glutSpecialFunc(keyPress);

    //glutMouseFunc( mouseClickEvent );
    glutMotionFunc( mouseMotionEvent );
    //glutPassiveMotionFunc( mouseMotionEvent );


    glutMainLoop();
    return 0;
}


