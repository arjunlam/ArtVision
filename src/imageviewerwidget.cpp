#include "imageviewerwidget.h"
#include "ui_imageviewerwidget.h"
#include "imageviewer.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>

ImageViewerWidget::ImageViewerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageViewerWidget) {
    ui->setupUi(this);
    imageDirectory = "C:/Users/Public/Pictures/";

    connect(ui->loadButton, &QPushButton::clicked,
            this, &ImageViewerWidget::onLoadButtonClicked);

    connect(this, &ImageViewerWidget::messageSetSourceImage,
            ui->imageViewer, &ImageViewer::setImage);
    connect(this, &ImageViewerWidget::messageSetEdgeImage,
            ui->edgeViewer, &ImageViewer::setImage);
    connect(this, &ImageViewerWidget::messageSetIntersectionImage,
            ui->intersectionViewer, &ImageViewer::setImage);

    connect(ui->blurKernalSlider, &QSlider::valueChanged,
            [&](int) {calculateEdges();});
    connect(ui->kernalSizeSlider, &QSlider::valueChanged,
            [&](int) {calculateEdges();});
    connect(ui->lowThresholdSlider, &QSlider::valueChanged,
            [&](int) {calculateEdges();});
    connect(ui->ratioSlider, &QSlider::valueChanged,
            [&](int) {calculateEdges();});
}

ImageViewerWidget::~ImageViewerWidget() {
    delete ui;
}

void ImageViewerWidget::calculateEdges() {
    if (source.empty()) return;

    int lowThreshold = 1 + 2 * ui->lowThresholdSlider->value();
    int blurKernal = 1 + 2 * ui->blurKernalSlider->value();
    int kernalSize = 1 + 2 * ui->kernalSizeSlider->value();
    int ratio = 1 + 2 * ui->ratioSlider->value();

    cv::Mat greyscale;
    cv::cvtColor(source, greyscale, CV_BGR2GRAY);

    cv::blur(greyscale, edges, cv::Size(blurKernal, blurKernal));
    cv::Canny(edges, edges, lowThreshold, lowThreshold * ratio, kernalSize);

    emit messageSetEdgeImage(edges);
}

void ImageViewerWidget::onLoadButtonClicked() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), imageDirectory, tr("Image Files (*.png *.jpg *.bmp)"));
    if (filename.isEmpty()) {
    } else {
        ui->pathLineEdit->setText(filename);
        imageDirectory = QFileInfo(filename).path();
        source = cv::imread(filename.toStdString(), cv::IMREAD_COLOR);

        emit messageSetSourceImage(source);

        calculateEdges();
    }
}
