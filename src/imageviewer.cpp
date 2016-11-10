#include "imageviewer.h"

#include <QOpenGLFunctions>
#include <opencv2/opencv.hpp>

ImageViewer::ImageViewer(QWidget *parent) : QOpenGLWidget(parent) {
}


ImageViewer::~ImageViewer() {
}

#include <QDebug>
void ImageViewer::setImage(const cv::Mat &image) {
    if (image.channels() == 3) {
        cvtColor(image, mOrigImage, CV_BGR2RGBA);
    }
    else if (image.channels() == 1) {
        cvtColor(image, mOrigImage, CV_GRAY2RGBA);
    }
    else return;
    mRenderQtImg = QImage((const unsigned char*)(mOrigImage.data),
                          mOrigImage.cols, mOrigImage.rows,
                          mOrigImage.step1(), QImage::Format_RGB32);
    recalculatePosition();
    updateScene();
}


void ImageViewer::initializeGL() {
    makeCurrent();
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void ImageViewer::paintGL() {
    makeCurrent();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    renderImage();
}


void ImageViewer::resizeGL(int width, int height) {
    makeCurrent();
    glViewport(0, 0, (GLint)width, (GLint)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, width, -height, 0, 0, 1);

    glMatrixMode(GL_MODELVIEW);

    recalculatePosition();

    emit imageSizeChanged(mRenderWidth, mRenderHeight);

    updateScene();
}

void ImageViewer::updateScene() {
    if (this->isVisible()) {
        update();
    }
}


void ImageViewer::renderImage() {
    makeCurrent();
    glClear(GL_COLOR_BUFFER_BIT);

    if (!mRenderQtImg.isNull()) {
        glLoadIdentity();
        glPushMatrix();

        if (mResizedImg.width() <= 0) {
            if (mRenderWidth == mRenderQtImg.width() && mRenderHeight == mRenderQtImg.height()) {
                mResizedImg = mRenderQtImg;
            }
            else {
                mResizedImg = mRenderQtImg.scaled(QSize(mRenderWidth, mRenderHeight),
                                                  Qt::IgnoreAspectRatio,
                                                  Qt::SmoothTransformation);
            }
        }

        glRasterPos2i(mRenderPosX, mRenderPosY);
        glPixelZoom(1, -1);
        glDrawPixels(mResizedImg.width(), mResizedImg.height(), GL_RGBA, GL_UNSIGNED_BYTE, mResizedImg.bits());
        glPopMatrix();
        glFlush();
    }
}


void ImageViewer::recalculatePosition() {
    mImgRatio = (float)mOrigImage.cols/(float)mOrigImage.rows;

    mRenderWidth = this->size().width();
    mRenderHeight = floor(mRenderWidth / mImgRatio);

    if (mRenderHeight > this->size().height()) {
        mRenderHeight = this->size().height();
        mRenderWidth = floor(mRenderHeight * mImgRatio);
    }

    mRenderPosX = floor((this->size().width() - mRenderWidth) / 2);
    mRenderPosY = -floor((this->size().height() - mRenderHeight) / 2);

    mResizedImg = QImage();
}
