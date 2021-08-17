#include <GL/gl.h>
#include <GL/glut.h>

//#include <glm/glm.hpp>
//#include <GL/glew.h>

#include <iostream>
#include <cmath>

//    glutSolidCube(0.5);

float rX = 0.0;
float rY = 0.0;
float rZ = 0.0;

int lastX = 0;
int lastY = 0;

float scale_ = 1.0;

bool line_quad = false;

void init() {
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glMatrixMode (GL_MATRIX_MODE);
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

void DrawCube(float s) {
    glBegin(GL_QUADS);
        glColor3f(1.0, 0, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(s, 0, 0);

        glVertex3f(s, 0, s);
        glVertex3f(0, 0, s);
    glEnd();

    //
    glBegin(GL_QUADS);
        glColor3f(0, 1, 0);

        glVertex3f(s, 0, s);
        glVertex3f(0, 0, s);

        glVertex3f(0, s, s);
        glVertex3f(s, s, s);
    glEnd();

    //
    glBegin(GL_QUADS);
        glColor3f(0, 0, 1);

        glVertex3f(0, s, s);
        glVertex3f(s, s, s);

        glVertex3f(s, s, 0);
        glVertex3f(0, s, 0);
    glEnd();

    //
    glBegin(GL_QUADS);
        glColor3f(0.6, 0.4, 0);

        glVertex3f(s, s, 0);
        glVertex3f(0, s, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(s, 0, 0);
    glEnd();

    //
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.5, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, s);

        glVertex3f(0, s, s);
        glVertex3f(0, s, 0);
    glEnd();

    //
    glBegin(GL_QUADS);
        glColor3f(1.0, 0, 0.3);

        glVertex3f(s, 0, 0);
        glVertex3f(s, 0, s);

        glVertex3f(s, s, s);
        glVertex3f(s, s, 0);
    glEnd();
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

    DrawCube(0.3);

    glPopMatrix();
    glFlush();
    glutSwapBuffers();

    restore_rotate();
}

void keyPress(unsigned char key, int x, int y) {
    std::cerr << key;

    glutPostRedisplay();
}

void mouseClickEvent(int key, int state, int x, int y) {
    restore_rotate();

    if (key == 1 && state == 0) {
        if (!line_quad) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
        else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }

        line_quad = !line_quad;
    }

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

    glutPostRedisplay();
}

void mouseMotionEvent(int y, int x) {
    if (x - lastX > 0) {
        if (rX < 0)
            rX = 0;

        rX += 1;
    }
    else {
        if (rX > 0)
            rX = 0;

        rX -= 1;
    }

    if (y - lastY > 0) {
        if (rY < 0)
            rY = 0;

        rY += 1;
    }
    else {
        if (rY > 0)
            rY = 0;

        rY -= 1;
    }
    //
    if (x - lastX > 0 && y - lastY > 0) {
        if (rZ < 0)
            rZ = 0;

        rZ += 1;
    }
    else {
        if (rZ > 0)
            rZ = 0;

        rZ -= 1;
    }

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

//    glutSpecialFunc();
    glutKeyboardFunc(keyPress);
    glutMouseFunc( mouseClickEvent );
    glutMotionFunc( mouseMotionEvent );
//    glutPassiveMotionFunc( mouseMotionEvent );

    glutMainLoop();
    return 0;
}


