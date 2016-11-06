#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QSize>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_2_0>
#include <opencv2/core/core.hpp>

class ImageViewer : public QOpenGLWidget, protected QOpenGLFunctions_2_0
{
    Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = nullptr);

    ~ImageViewer();

signals:
    void imageSizeChanged(int width, int height);

public slots:
    void setImage(const cv::Mat &image);

    // METHODS
protected:
    void initializeGL();

    void paintGL();

    void resizeGL(int width, int height);

    void updateScene();

    void renderImage();

    void recalculatePosition();

    // MEMBERS
protected:
    QImage mRenderQtImg;
    QImage mResizedImg;
    cv::Mat mOrigImage;

    float mImgRatio;

    int mRenderWidth;
    int mRenderHeight;
    int mRenderPosX;
    int mRenderPosY;
};

#endif // IMAGEVIEWER_H
