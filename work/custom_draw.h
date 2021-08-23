#ifndef CUSTOM_DRAW_H
#define CUSTOM_DRAW_H

#include <QOpenGLWidget>

class custom_draw : public QOpenGLWidget {
public:
    custom_draw(QWidget* pwgt = nullptr);

protected:
    virtual void initializeGL() override;
    virtual void resizeGL(GLint, GLint) override;
    virtual void paintGL() override;

    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void mouseMoveEvent(QMouseEvent*) override;
    virtual void wheelEvent(QWheelEvent*) override;

    GLuint draw_1();
    GLuint draw_2();

private:
    GLuint m_nCube;
    GLfloat m_xRotate;
    GLfloat m_yRotate;
    QPoint m_ptPosition;

    GLfloat m_scale;
    bool m_is_line;

    QVector<QVector<GLfloat>> m_vertices_1;
    QVector<QVector<GLfloat>> m_vertices_2;
};

#endif // CUSTOM_DRAW_H
