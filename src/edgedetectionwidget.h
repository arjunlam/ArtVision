#ifndef EDGEDETECTIONWIDGET_H
#define EDGEDETECTIONWIDGET_H

#include <QWidget>
#include <QString>

#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include "imageviewerwidget.h"

namespace Ui {
class EdgeDetectionWidget;
}

class EdgeDetectionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EdgeDetectionWidget(QWidget *parent = nullptr);
    ~EdgeDetectionWidget();

    void calculateEdges();

public slots:
    void onLoadButtonClicked();

signals:
    void messageSetSourceImage(const cv::Mat &image, GLenum minFilter, GLenum magFilter, GLenum wrapFilter);
    void messageSetEdgeImage(const cv::Mat &image, GLenum minFilter, GLenum magFilter, GLenum wrapFilter);
    void messageSetIntersectionImage(const cv::Mat &image, GLenum minFilter, GLenum magFilter, GLenum wrapFilter);

    // MEMBERS
protected:
    Ui::EdgeDetectionWidget *ui;
    QString imageDirectory;

    cv::Mat source_image;
    cv::Mat edge_image;
    cv::Mat intersection_image;
};

#endif // EDGEDETECTIONWIDGET_H
