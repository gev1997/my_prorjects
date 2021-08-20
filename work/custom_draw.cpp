#include "custom_draw.h"

#include <QOpenGLFunctions>
#include <QKeyEvent>

#include <iostream>

#define DRAW_FUNCTION draw_2

custom_draw::custom_draw(QWidget* pwgt) : QOpenGLWidget{pwgt}
    , m_xRotate {0}
    , m_yRotate {0}
    , m_scale {1}
    , m_is_line {false}
    , m_vertices_1 {
            {0.325, 6.675, 0.15,
             0.325, 6.675, 0,
             0.325, 0.325, 0,
             0.325, 0.325, 0.15},

            {9.675, 6.675, 0.0,
              9.675, 6.675, 0.15,
              9.675, 0.325, 0.15,
              9.675, 0.325, 0.0},

            {0.325, 0.325, 0.15,
              0.325, 0.325, 0.0,
              9.675, 0.325, 0.0,
              9.675, 0.325, 0.15},

            {9.675, 6.675, 0.15,
             9.675, 6.675, 0,
             0.325, 6.675, 0,
             0.325, 6.675, 0.15},

            {9.675, 6.675, 0.15,
            0.325, 6.675, 0.15,
            0.325, 0.325, 0.15,
            9.675, 0.325, 0.15},

            {0.325, 0.325, 0,
             0.325, 6.675, 0,
             9.675, 6.675, 0,
             9.675, 0.325, 0}
        }
{}

void custom_draw::initializeGL() {
    QOpenGLFunctions* pFunc = QOpenGLContext::currentContext()->functions();
    pFunc->glClearColor(0, 0, 0, 1);

    pFunc->glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    m_nCube = DRAW_FUNCTION();
}

void custom_draw::resizeGL(GLint width, GLint height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);

    glFrustum(-1.0, 1.0, -1.0, 1.0, 2, 50.0);
    glTranslatef(0, -5, -15);
//    glRotatef(90, 0, 0, 1);
    //glOrtho(-50, 50, -50, 50, -50, 50);
}

void custom_draw::paintGL() {
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

void custom_draw::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::RightButton) {
        m_is_line = !m_is_line;
        update();
    }

    m_ptPosition = event->pos();
}

void custom_draw::mouseMoveEvent(QMouseEvent* event) {
    m_xRotate += 180 * (GLfloat)(event->y() - m_ptPosition.y()) / height();
    m_yRotate += 180 * (GLfloat)(event->x() - m_ptPosition.x()) / width();
    update();

    m_ptPosition = event->pos();
}

void custom_draw::wheelEvent(QWheelEvent* event) {
    if (event->angleDelta().y() > 0) {
        m_scale += 0.1;
    } else if (event->angleDelta().y() < 0) {
        m_scale -= 0.1;
    }

    update();
}

GLuint custom_draw::draw_1() {
    GLuint n_gen_lists = glGenLists(1);

    glNewList(n_gen_lists, GL_COMPILE);
        glColor3f(0.2, 0.4, 0.4);

        for (int i = 0; i < m_vertices_1.size(); ++i) {
            for (int j = 0; j < m_vertices_1[i].size(); j += 3) {
                glBegin(GL_QUADS);
                    glVertex3f(m_vertices_1[i][j]
                               , m_vertices_1[i][j + 1]
                               , m_vertices_1[i][j + 2]);
                glEnd();
            }
        }
     glEndList();

     return n_gen_lists;
}

GLuint custom_draw::draw_2() {
    GLuint n_gen_lists = glGenLists(1);

    glNewList(n_gen_lists, GL_COMPILE);


    glEndList();

    return n_gen_lists;
}
