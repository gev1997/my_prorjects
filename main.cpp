#include <GL/gl.h>
#include <GL/glut.h>

#include <vector>

//#include <glm/glm.hpp>
//#include <GL/glew.h>

#include <iostream>
#include <cmath>

/*
 * character
    glOrtho(0,50,0,50,0,10);
    glRasterPos2i(30, 20);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'G');

 */

//    glutSolidCube(0.5);

float rX = 0.0;
float rY = 0.0;
float rZ = 0.0;

int lastX = 0;
int lastY = 0;

float scale_ = 1.0;

void init() {
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    //glFrustum(-1,1, -1,1, -2, 8);
    //glOrtho (-1.5, 1.5, -1.5, 1.5, -1.0, 1.0);
}

void restore_rotate() {
    rX = rY = rZ = 0;
}

void DrawX() {
    glPushMatrix();

    glTranslatef(0.85, 0, 0);
    glScalef(0.4, 0.5, 0.4);
    glLineWidth(4);

    glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glVertex3f(0.1, 0.1, 0);
        glVertex3f(-0.1, -0.1, 0);
        glVertex3f(-0.1, 0.1, 0);
        glVertex3f(0.1, -0.1, 0);
    glEnd();

    glLineWidth(1);
    glPopMatrix();
}

void DrawY() {
    glPushMatrix();
    glTranslatef(0, 0.90, 0);
    glScalef(0.4, 0.5, 0.4);
    glLineWidth(4);

    glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(-0.1, 0.1, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0.1, 0.1, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, -0.1, 0);
    glEnd();

    glLineWidth(1);
    glPopMatrix();
}

void DrawZ() {
    glPushMatrix();
    glTranslatef(0, 0, 0.85);
    glScalef(0.4, 0.5, 0.4);
    glLineWidth(4);

    glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glVertex3f(-0.1, 0.1, 0);
        glVertex3f(0.1, 0.1, 0);

        glVertex3f(0.1, 0.1, 0);
        glVertex3f(-0.1, -0.1, 0);

        glVertex3f(-0.1, -0.1, 0);
        glVertex3f(0.1, -0.1, 0);
    glEnd();

    glLineWidth(1);
    glPopMatrix();
}


void DrawArrow(char axis) {
    glPushMatrix();

    switch(axis) {
        case 'x' :
            glTranslatef(0.8, 0, 0);
            break;
        case 'y' :
            glTranslatef(0, 0.8, 0);
            break;
        case 'z' :
            glTranslatef(0, 0, 0.8);
            break;
    }

    glScalef(0.3, 0.3, 0.3);
    glLineWidth(2);

    glBegin(GL_LINES);
        glColor3f(0, 1, 0);

        switch(axis) {
            case 'x':
                glVertex3f(0, 0, 0);
                glVertex3f(-0.1, 0.1, 0);

                glVertex3f(0, 0, 0);
                glVertex3f(-0.1, -0.1, 0);
                break;
            case 'y':
                glVertex3f(0, 0, 0);
                glVertex3f(-0.1, -0.1, 0);

                glVertex3f(0, 0, 0);
                glVertex3f(0.1, -0.1, 0);
                break;
            case 'z' :
                glVertex3f(0, 0, 0);
                glVertex3f(0, -0.1, -0.1);

                glVertex3f(0, 0, 0);
                glVertex3f(0, 0.1, -0.1);
        }

    glEnd();

    glLineWidth(1);
    glPopMatrix();
}

void display() {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glRotatef(rX, 1, 0, 0);
    glRotatef(rY, 0, 1, 0);
    glRotatef(rZ, 0, 0, 1);

    glPushMatrix();

    glBegin(GL_LINES);
        glColor3f(0.9, 1, 0.9);

        glVertex3f(0, 0, 0);
        glVertex3f(0.8, 0, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, 0.8, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 0.8);
    glEnd();

    DrawX();
    DrawY();
    DrawZ();
    DrawArrow('x');
    DrawArrow('y');
    DrawArrow('z');

    //
    glBegin(GL_QUADS);
        glColor3f(1.0, 0, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0.5, 0, 0);

        glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0, 0, 0.5);
    glEnd();

    //
    glBegin(GL_QUADS);
        glColor3f(0, 1, 0);

        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0, 0, 0.5);

        glVertex3f(0, 0.5, 0.5);
        glVertex3f(0.5, 0.5, 0.5);
    glEnd();

    //
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.0, 0.5);

        glVertex3f(0, 0.5, 0.5);
        glVertex3f(0.5, 0.5, 0.5);

        glVertex3f(0.5, 0.5, 0);
        glVertex3f(0, 0.5, 0);
    glEnd();

    //
    glBegin(GL_QUADS);
        glColor3f(0.2, 0.0, 1.0);

        glVertex3f(0.5, 0.5, 0);
        glVertex3f(0, 0.5, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0.5, 0, 0);
    glEnd();

    //
    glBegin(GL_QUADS);
        glColor3f(0.2, 0.3, 1.0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 0.5);

        glVertex3f(0, 0.5, 0.5);
        glVertex3f(0, 0.5, 0);
    glEnd();

    //
    glBegin(GL_QUADS);
        glColor3f(0.8, 0.3, 1.0);

        glVertex3f(0.5, 0, 0);
        glVertex3f(0.5, 0, 0.5);

        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(0.5, 0.5, 0);
    glEnd();

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void keyPress(int key, int x, int y) {
    std::cerr << key;

    glutPostRedisplay();
}

void mouseClickEvent(int key, int state, int x, int y) {
    restore_rotate();

    if ( (x > 0 && x < 50) && (y > 0 && y < 50) )
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else if ( (x > 0 && x < 50) && (y > 50 && y < 100) )
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    if (key == 3) {
        if (scale_ < 1) {
            scale_ = 1;
        }
        scale_ += 0.01;
    }
    else if (key == 4) {
        if (scale_ > 1) {
            scale_ = 1;
        }
        scale_ -= 0.01;
    }

    glScalef(scale_, scale_, scale_);
    /*
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
*/
    glutPostRedisplay();
}

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

    init ();

    glutDisplayFunc(display);

//    glutSpecialFunc(keyPress);

    glutMouseFunc( mouseClickEvent );
    glutMotionFunc( mouseMotionEvent );
    //glutPassiveMotionFunc( mouseMotionEvent );


    glutMainLoop();
    return 0;
}


