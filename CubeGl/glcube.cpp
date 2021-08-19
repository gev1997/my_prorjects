#include "glcube.h"

#include <QOpenGLFunctions>
#include <QKeyEvent>

#include <iostream>

GLCube::GLCube(QWidget* pwgt)
    : QOpenGLWidget{pwgt}
    , m_xRotate {0}
    , m_yRotate {0}
    , m_scale {1}
    , m_is_line {false}
{}

void GLCube::initializeGL() {
    QOpenGLFunctions* pFunc = QOpenGLContext::currentContext()->functions();
    pFunc->glClearColor(0, 0, 0, 1);

    pFunc->glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    m_nCube = createCube(1.0f);
}

void GLCube::resizeGL(GLint width, GLint height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
}

void GLCube::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (m_is_line) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    glTranslatef(0.0, 0.0, -6);
    glRotatef(m_xRotate, 1.0, 0.0, 0.0);
    glRotatef(m_yRotate, 0.0, 1.0, 0.0);
    glScalef(m_scale, m_scale, m_scale);

    glCallList(m_nCube);
}

void GLCube::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::RightButton) {
        m_is_line = !m_is_line;
        update();
    }

    m_ptPosition = event->pos();
}

void GLCube::mouseMoveEvent(QMouseEvent* event) {
    m_xRotate += 180 * (GLfloat)(event->y() - m_ptPosition.y()) / height();
    m_yRotate += 180 * (GLfloat)(event->x() - m_ptPosition.x()) / width();
    update();

    m_ptPosition = event->pos();
}

void GLCube::wheelEvent(QWheelEvent* event) {
    if (event->angleDelta().y() > 0) {
        m_scale += 0.1;
    } else if (event->angleDelta().y() < 0) {
        m_scale -= 0.1;
    }

    update();
}

void drawX() {
    glPushMatrix();

    glTranslatef(2.8, 0, 0);
    glLineWidth(4);

    glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glVertex3f(0.2, 0.2, 0);
        glVertex3f(-0.2, -0.2, 0);
        glVertex3f(-0.2, 0.2, 0);
        glVertex3f(0.2, -0.2, 0);
    glEnd();

    glLineWidth(1);
    glPopMatrix();
}

void drawY() {
    glPushMatrix();
    glTranslatef(0, 2.8, 0);
    glLineWidth(4);

    glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(-0.2, 0.2, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0.2, 0.2, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, -0.2, 0);
    glEnd();

    glLineWidth(1);
    glPopMatrix();
}

void drawZ() {
    glPushMatrix();
    glTranslatef(0, 0, 2.8);
    glLineWidth(4);

    glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glVertex3f(-0.2, 0.2, 0);
        glVertex3f(0.2, 0.2, 0);

        glVertex3f(0.2, 0.2, 0);
        glVertex3f(-0.2, -0.2, 0);

        glVertex3f(-0.2, -0.2, 0);
        glVertex3f(0.2, -0.2, 0);
    glEnd();

    glLineWidth(1);
    glPopMatrix();
}

void drawAxises() {
    glBegin(GL_LINES);
        glColor3f(0.9, 1, 0.9);

        glVertex3f(0, 0, 0);
        glVertex3f(2.5, 0, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, 2.5, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 2.5);
    glEnd();
}

void DrawArrow(char axis) {
    glPushMatrix();

    switch(axis) {
        case 'x' :
            glTranslatef(2.5, 0, 0);
            break;
        case 'y' :
            glTranslatef(0, 2.5, 0);
            break;
        case 'z' :
            glTranslatef(0, 0, 2.5);
            break;
    }

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

GLuint GLCube::createCube(GLfloat s /* = 1.0f */) {
    GLuint n_gen_lists = glGenLists(1);

    glNewList(n_gen_lists, GL_COMPILE);
        drawX();
        drawY();
        drawZ();

        drawAxises();

        DrawArrow('x');
        DrawArrow('y');
        DrawArrow('z');

        glBegin(GL_QUADS);
            glColor3f(0.2, 0.4, 0);

            glVertex3f(-s, s, s);
            glVertex3f(s, s, s);

            glVertex3f(s, -s, s);
            glVertex3f(-s, -s, s);
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(0.2, 0.4, 0);

            glVertex3f(s, s, s);
            glVertex3f(s, s, -s);

            glVertex3f(s, -s, -s);
            glVertex3f(s, -s, s);
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(0.2, 0.4, 0);

            glVertex3f(s, s, -s);
            glVertex3f(-s, s, -s);

            glVertex3f(-s, -s, -s);
            glVertex3f(s, -s, -s);
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(0.2, 0.4, 0);

            glVertex3f(-s, s, -s);
            glVertex3f(-s, s, s);

            glVertex3f(-s, -s, s);
            glVertex3f(-s, -s, -s);
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(0.2, 0.4, 0);

            glVertex3f(-s, s, s);
            glVertex3f(s, s, s);

            glVertex3f(s, s, -s);
            glVertex3f(-s, s, -s);
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(0.2, 0.4, 0);

            glVertex3f(-s, -s, s);
            glVertex3f(s, -s, s);

            glVertex3f(s, -s, -s);
            glVertex3f(-s, -s, -s);
        glEnd();
     glEndList();

     return n_gen_lists;
}
