#ifndef IMAGEVIEWERWIDGET_H
#define IMAGEVIEWERWIDGET_H

#include <QSize>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_2_0>
#include <opencv2/core/core.hpp>

class ImageViewerWidget : public QOpenGLWidget, protected QOpenGLFunctions_2_0
{
    Q_OBJECT

public:
    explicit ImageViewerWidget(QWidget *parent = nullptr);
    ~ImageViewerWidget();

public slots:
    void onSetImage(const cv::Mat &image, GLenum minFilter, GLenum magFilter, GLenum wrapFilter);
    void onClearImage();

    // METHODS
protected:
    void initializeGL();

    void paintGL();

    void resizeGL(int width, int height);

    void uploadTexture(const cv::Mat &image, GLenum minFilter, GLenum magFilter, GLenum wrapFilter);

protected:
    GLuint texture;
    GLuint depth;

    GLuint textureHeight;
    GLuint textureWidth;
    GLfloat textureWidthRatio;
    GLfloat textureHeightRatio;
};

#endif // IMAGEVIEWERWIDGET_H
