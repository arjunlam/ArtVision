#include "imageviewerwidget.h"

#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/imgcodecs.hpp>
#include <QDebug>

ImageViewerWidget::ImageViewerWidget(QWidget *parent) : QOpenGLWidget(parent) {
    texture = 0;
}


ImageViewerWidget::~ImageViewerWidget(){
    onClearImage();
}

void ImageViewerWidget::onSetImage(const cv::Mat &image, GLenum minFilter, GLenum magFilter, GLenum wrapFilter){
    onClearImage();

    uploadTexture(image, minFilter, magFilter, wrapFilter);

    if (this->isVisible()) {
        update();
    }

}

void ImageViewerWidget::onClearImage() {
    makeCurrent();
    if (texture != 0) glDeleteTextures(1, &texture);
    texture = 0;

    if (depth != 0) glDeleteTextures(1, &depth);
    depth = 0;
}


void ImageViewerWidget::initializeGL(){
    makeCurrent();
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void ImageViewerWidget::paintGL(){
    makeCurrent();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0.5f * width(), 0.5f * width(), 0.5f * height(), -0.5f * height(), 0.0, 1.f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glViewport(0, 0, width(), height());

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture);

    const float x = 0.5f * textureWidthRatio * width();
    const float y = 0.5f * textureHeightRatio * height();

    glBegin(GL_TRIANGLE_STRIP);
        glTexCoord2d(0.0,0.0); glVertex2d(-x, -y);
        glTexCoord2d(1.0,0.0); glVertex2d(x, -y);
        glTexCoord2d(1.0,1.0); glVertex2d(x, y);
        glTexCoord2d(0.0,0.0); glVertex2d(-x, -y);
        glTexCoord2d(0.0,1.0); glVertex2d(-x, y);
    glEnd();
}


void ImageViewerWidget::resizeGL(int w, int h){}

void ImageViewerWidget::uploadTexture(const cv::Mat &image, GLenum minFilter, GLenum magFilter, GLenum wrapFilter) {
    textureHeight = image.rows;
    textureWidth = image.cols;

    textureWidthRatio = static_cast<GLfloat>(textureWidth) / static_cast<GLfloat>(textureHeight);
    textureHeightRatio = 1.0f / textureWidthRatio;

    textureWidthRatio = (textureWidthRatio > 1.0f) ? 1.0f : textureWidthRatio;
    textureHeightRatio = (textureHeightRatio > 1.0f) ? 1.0f : textureHeightRatio;

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    if (magFilter == GL_LINEAR_MIPMAP_LINEAR  ||
        magFilter == GL_LINEAR_MIPMAP_NEAREST ||
        magFilter == GL_NEAREST_MIPMAP_LINEAR ||
        magFilter == GL_NEAREST_MIPMAP_NEAREST) {
        magFilter = GL_LINEAR;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapFilter);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    switch (image.type()) {
    case CV_8U:
        glTexImage2D(GL_TEXTURE_2D,
                         0,
                         GL_RGB,
                         image.cols,
                         image.rows,
                         0,
                         GL_LUMINANCE,
                         GL_UNSIGNED_BYTE,
                         image.ptr());
        break;
    case CV_16U:
        glTexImage2D(GL_TEXTURE_2D,
                         0,
                         GL_RGB,
                         image.cols,
                         image.rows,
                         0,
                         GL_LUMINANCE,
                         GL_UNSIGNED_SHORT,
                         image.ptr());
                     break;
    case CV_8UC3:
        glTexImage2D(GL_TEXTURE_2D,
                         0,
                         GL_RGB,
                         image.cols,
                         image.rows,
                         0,
                         GL_BGR,
                         GL_UNSIGNED_BYTE,
                         image.ptr());
        break;
    case CV_32F:
        glTexImage2D(GL_TEXTURE_2D,
                         0,
                         GL_RGB,
                         image.cols,
                         image.rows,
                         0,
                         GL_LUMINANCE,
                         GL_FLOAT,
                         image.ptr());
        break;
    default:
        qDebug() << Q_FUNC_INFO << "Unhandled texture type";
    }

    glBindTexture(GL_TEXTURE_2D, 0);
}
