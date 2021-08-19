#ifndef GLCUBE_H
#define GLCUBE_H

#include <QOpenGLWidget>

class GLCube : public QOpenGLWidget {
public:
    GLCube(QWidget* pwgt = nullptr);

protected:
    virtual void initializeGL() override;
    virtual void resizeGL(GLint, GLint) override;
    virtual void paintGL() override;

    virtual void mousePressEvent(QMouseEvent*) override;
    virtual void mouseMoveEvent(QMouseEvent*) override;
    virtual void wheelEvent(QWheelEvent*) override;

    GLuint createCube(GLfloat fSize = 1.0f);

private:
    GLuint m_nCube;
    GLfloat m_xRotate;
    GLfloat m_yRotate;
    QPoint m_ptPosition;

    GLfloat m_scale;
    bool m_is_line;
};

#endif // GLCUBE_H
