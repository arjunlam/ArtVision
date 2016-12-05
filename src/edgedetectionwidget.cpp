#include "edgedetectionwidget.h"
#include "ui_edgedetectionwidget.h"
#include "core.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>

EdgeDetectionWidget::EdgeDetectionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EdgeDetectionWidget) {
    ui->setupUi(this);
    imageDirectory = "C:/Users/Public/Pictures/";

    connect(ui->loadButton, &QPushButton::clicked,
            this, &EdgeDetectionWidget::onLoadButtonClicked);

    connect(this, &EdgeDetectionWidget::messageSetSourceImage,
            ui->imageViewer, &ImageViewerWidget::onSetImage);
    connect(this, &EdgeDetectionWidget::messageSetEdgeImage,
            ui->edgeViewer, &ImageViewerWidget::onSetImage);
    connect(this, &EdgeDetectionWidget::messageSetIntersectionImage,
            ui->intersectionViewer, &ImageViewerWidget::onSetImage);
    connect(ui->calculateEdgesButton, &QPushButton::clicked,
            this, &EdgeDetectionWidget::onCalculateEdges);
}

EdgeDetectionWidget::~EdgeDetectionWidget() {
    delete ui;
}

void EdgeDetectionWidget::onCalculateEdges() {
    if (source_image.empty()) return;

    cv::Mat greyscale;
    cv::bilateralFilter(source_image.clone(), source_image, 7, 77, 77);

    cv::cvtColor(source_image, greyscale, CV_BGR2GRAY);

    cv::Mat ostu;
    double ostu_threshold = cv::threshold(greyscale, ostu, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

    uchar upper = ostu_threshold;
    uchar lower = 0.5 * ostu_threshold;

    cv::Canny(greyscale, edge_image, lower, upper);

    std::vector<cv::Vec4i> lines;
    lines.reserve(20000);
    cv::HoughLinesP(edge_image, lines, 2, CV_PI/180, 20, 5, 2);

    cv::Mat temp_edge = cv::Mat::zeros(edge_image.size(), CV_8U);
    foreach (auto line, lines) {
        cv::line(temp_edge, cv::Point(line[0], line[1]), cv::Point(line[2], line[3]), cv::Scalar(255), 1, CV_AA);
    }

    edge_image = temp_edge.clone();

    intersection_image = cv::Mat(source_image.size(), CV_8U);

    std::vector<cv::Vec2f> intersections;
    calculate_intersections(lines, intersections);
    visualize_intersections<uchar>(intersections, intersection_image, 10);

    cv::Vec2f vanishing_point;
    calculate_vanishing_point(intersections, vanishing_point, 100, 2.0f);

    std::vector<cv::Vec4i> parallel_lines;
    calculate_parallel_lines(vanishing_point, lines, parallel_lines, 0.99f);


    cv::Mat depths;
    calculate_depth(source_image.size(), vanishing_point, parallel_lines, depths);

    double minValue, maxValue;
    cv::minMaxIdx(depths, &minValue, &maxValue);

    depths -= minValue;
    depths /= maxValue;

    emit messageSetSourceImage(depths, GL_LINEAR, GL_LINEAR, GL_CLAMP);
    emit messageSetEdgeImage(edge_image, GL_LINEAR, GL_LINEAR, GL_CLAMP);
    emit messageSetIntersectionImage(intersection_image, GL_LINEAR, GL_LINEAR, GL_CLAMP);

}

void EdgeDetectionWidget::onLoadButtonClicked() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), imageDirectory, tr("Image Files (*.png *.jpg *.bmp)"));
    if (filename.isEmpty()) {
    } else {
        ui->pathLineEdit->setText(filename);
        imageDirectory = QFileInfo(filename).path();
        source_image = cv::imread(filename.toStdString(), cv::IMREAD_COLOR);

        emit messageSetSourceImage(source_image, GL_LINEAR, GL_LINEAR, GL_CLAMP);
    }
}
