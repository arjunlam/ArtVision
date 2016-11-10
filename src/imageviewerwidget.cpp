#include "imageviewerwidget.h"
#include "ui_imageviewerwidget.h"

#include <QFileDialog>
#include <QFileInfo>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>

ImageViewerWidget::ImageViewerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageViewerWidget) {
    ui->setupUi(this);
    imageDirectory = "C:/Users/Public/Pictures/";

    connect(ui->loadButton, &QPushButton::clicked,
            this, &ImageViewerWidget::onLoadButtonClicked);
}

ImageViewerWidget::~ImageViewerWidget() {
    delete ui;
}

void ImageViewerWidget::onLoadButtonClicked() {
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), imageDirectory, tr("Image Files (*.png *.jpg *.bmp)"));
    if (filename.isEmpty()) {
    } else {
        ui->pathLineEdit->setText(filename);
        imageDirectory = QFileInfo(filename).path();
        cv::Mat image = cv::imread(filename.toStdString(), cv::IMREAD_COLOR);
        ui->imageViewer->setImage(image);
    }
}
