#include "edgedetectionwidget.h"
#include "ui_edgedetectionwidget.h"
#include "core.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>

#include "core.h"

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

    int lowThreshold = 1 + 2 * ui->lowThresholdSlider->value();
    int blurKernal = 1 + 2 * ui->blurKernalSlider->value();
    int kernalSize = 1 + 2 * ui->kernalSizeSlider->value();
    int ratio = 1 + 2 * ui->ratioSlider->value();

    cv::Mat greyscale;
    cv::cvtColor(source_image, greyscale, CV_BGR2GRAY);

    cv::blur(greyscale, edge_image, cv::Size(blurKernal, blurKernal));
    cv::Canny(edge_image, edge_image, lowThreshold, lowThreshold * ratio, kernalSize);

    std::vector<cv::Vec4i> lines;
    lines.reserve(20000);
    cv::HoughLinesP(edge_image, lines, 1, CV_PI/180, 50, 50, 10);

    cv::Mat temp_edge = cv::Mat::zeros(edge_image.size(), CV_8UC1);
    foreach (auto line, lines) {
        cv::line(temp_edge, cv::Point(line[0], line[1]), cv::Point(line[2], line[3]), cv::Scalar(255), 1, CV_AA);
    }

    edge_image = temp_edge.clone();
    emit messageSetEdgeImage(edge_image, GL_LINEAR, GL_LINEAR, GL_CLAMP);

    std::vector<cv::Vec2f> intersections;
    calculate_intersections(lines, intersections);

    intersection_image = cv::Mat(source_image.size(), CV_8U);
    visualize_intersections<uchar>(intersections, intersection_image);

    cv::Vec2f vanishing_point;
    calculate_vanishing_point(intersections,vanishing_point, 9, 3.0f);

    std::vector<cv::Vec4i> parallel_lines;
    calculate_parallel_lines(vanishing_point, lines, parallel_lines, 0.97f);

    cv::circle(source_image, cv::Point2i(vanishing_point[0], vanishing_point[1]), 0.01f * source_image.rows, cv::Scalar(0, 0, 255), -1);
    for (auto parallel_line : parallel_lines) {
        cv::line(source_image, cv::Point(parallel_line[0], parallel_line[1]), cv::Point(parallel_line[2], parallel_line[3]), cv::Scalar(255), 0.005f * source_image.rows, CV_AA);
    }

    emit messageSetSourceImage(source_image, GL_LINEAR, GL_LINEAR, GL_CLAMP);
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
