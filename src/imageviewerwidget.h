#ifndef IMAGEVIEWERWIDGET_H
#define IMAGEVIEWERWIDGET_H

#include <QWidget>
#include <QString>

#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>

namespace Ui {
class ImageViewerWidget;
}

class ImageViewerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageViewerWidget(QWidget *parent = nullptr);
    ~ImageViewerWidget();

    void calculateEdges();

public slots:
    void onLoadButtonClicked();

signals:
    void messageSetSourceImage(const cv::Mat &image);
    void messageSetEdgeImage(const cv::Mat &image);
    void messageSetIntersectionImage(const cv::Mat &image);

    // MEMBERS
protected:
    Ui::ImageViewerWidget *ui;
    QString imageDirectory;

    cv::Mat source;
    cv::Mat edges;
    cv::Mat intersections;
};

#endif // IMAGEVIEWERWIDGET_H
