#include "edgedetectionwidget.h"
#include "ui_edgedetectionwidget.h"

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

    connect(ui->blurKernalSlider, &QSlider::valueChanged,
            [&](int) {calculateEdges();});
    connect(ui->kernalSizeSlider, &QSlider::valueChanged,
            [&](int) {calculateEdges();});
    connect(ui->lowThresholdSlider, &QSlider::valueChanged,
            [&](int) {calculateEdges();});
    connect(ui->ratioSlider, &QSlider::valueChanged,
            [&](int) {calculateEdges();});
}

EdgeDetectionWidget::~EdgeDetectionWidget() {
    delete ui;
}

void EdgeDetectionWidget::calculateEdges() {
    if (source.empty()) return;

    int lowThreshold = 1 + 2 * ui->lowThresholdSlider->value();
    int blurKernal = 1 + 2 * ui->blurKernalSlider->value();
    int kernalSize = 1 + 2 * ui->kernalSizeSlider->value();
    int ratio = 1 + 2 * ui->ratioSlider->value();

    cv::Mat greyscale;
    cv::cvtColor(source, greyscale, CV_BGR2GRAY);

    cv::blur(greyscale, edges, cv::Size(blurKernal, blurKernal));
    cv::Canny(edges, edges, lowThreshold, lowThreshold * ratio, kernalSize);


    std::vector<cv::Vec4i> lines;
    lines.reserve(5000);
    cv::HoughLinesP(edges, lines, 1, CV_PI/180, 50, 50, 10);

    cv::Mat temp_edge = cv::Mat::zeros(edges.size(), CV_8UC1);
    foreach (auto line, lines) {
        cv::line(temp_edge, cv::Point(line[0], line[1]), cv::Point(line[2], line[3]), cv::Scalar(255), 1, CV_AA);
    }

    edges = temp_edge.clone();
    emit messageSetEdgeImage(edges, GL_LINEAR, GL_LINEAR, GL_CLAMP);

}

void EdgeDetectionWidget::onLoadButtonClicked() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), imageDirectory, tr("Image Files (*.png *.jpg *.bmp)"));
    if (filename.isEmpty()) {
    } else {
        ui->pathLineEdit->setText(filename);
        imageDirectory = QFileInfo(filename).path();
        source = cv::imread(filename.toStdString(), cv::IMREAD_COLOR);

        emit messageSetSourceImage(source, GL_LINEAR, GL_LINEAR, GL_CLAMP);

        calculateEdges();
    }
}
