/********************************************************************************
** Form generated from reading UI file 'imageviewerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWERWIDGET_H
#define UI_IMAGEVIEWERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imageviewer.h"

QT_BEGIN_NAMESPACE

class Ui_ImageViewerWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    ImageViewer *imageViewer;
    ImageViewer *edgeViewer;
    ImageViewer *intersectionViewer;
    QFormLayout *formLayout;
    QLabel *kernalSizeLabel;
    QSlider *kernalSizeSlider;
    QLabel *ratioLabel;
    QSlider *ratioSlider;
    QLabel *lowThresholdLabel;
    QSlider *lowThresholdSlider;
    QPushButton *loadButton;
    QLineEdit *pathLineEdit;
    QLabel *blurKernalLabel;
    QSlider *blurKernalSlider;

    void setupUi(QWidget *ImageViewerWidget)
    {
        if (ImageViewerWidget->objectName().isEmpty())
            ImageViewerWidget->setObjectName(QStringLiteral("ImageViewerWidget"));
        ImageViewerWidget->resize(580, 322);
        verticalLayout = new QVBoxLayout(ImageViewerWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        imageViewer = new ImageViewer(ImageViewerWidget);
        imageViewer->setObjectName(QStringLiteral("imageViewer"));
        imageViewer->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(imageViewer);

        edgeViewer = new ImageViewer(ImageViewerWidget);
        edgeViewer->setObjectName(QStringLiteral("edgeViewer"));

        horizontalLayout_2->addWidget(edgeViewer);

        intersectionViewer = new ImageViewer(ImageViewerWidget);
        intersectionViewer->setObjectName(QStringLiteral("intersectionViewer"));

        horizontalLayout_2->addWidget(intersectionViewer);


        verticalLayout->addLayout(horizontalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        kernalSizeLabel = new QLabel(ImageViewerWidget);
        kernalSizeLabel->setObjectName(QStringLiteral("kernalSizeLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, kernalSizeLabel);

        kernalSizeSlider = new QSlider(ImageViewerWidget);
        kernalSizeSlider->setObjectName(QStringLiteral("kernalSizeSlider"));
        kernalSizeSlider->setMinimum(1);
        kernalSizeSlider->setMaximum(3);
        kernalSizeSlider->setSingleStep(1);
        kernalSizeSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, kernalSizeSlider);

        ratioLabel = new QLabel(ImageViewerWidget);
        ratioLabel->setObjectName(QStringLiteral("ratioLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, ratioLabel);

        ratioSlider = new QSlider(ImageViewerWidget);
        ratioSlider->setObjectName(QStringLiteral("ratioSlider"));
        ratioSlider->setMinimum(0);
        ratioSlider->setMaximum(100);
        ratioSlider->setSingleStep(1);
        ratioSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(3, QFormLayout::FieldRole, ratioSlider);

        lowThresholdLabel = new QLabel(ImageViewerWidget);
        lowThresholdLabel->setObjectName(QStringLiteral("lowThresholdLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lowThresholdLabel);

        lowThresholdSlider = new QSlider(ImageViewerWidget);
        lowThresholdSlider->setObjectName(QStringLiteral("lowThresholdSlider"));
        lowThresholdSlider->setMinimum(0);
        lowThresholdSlider->setMaximum(100);
        lowThresholdSlider->setSingleStep(1);
        lowThresholdSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(4, QFormLayout::FieldRole, lowThresholdSlider);

        loadButton = new QPushButton(ImageViewerWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        formLayout->setWidget(5, QFormLayout::LabelRole, loadButton);

        pathLineEdit = new QLineEdit(ImageViewerWidget);
        pathLineEdit->setObjectName(QStringLiteral("pathLineEdit"));
        pathLineEdit->setEnabled(false);

        formLayout->setWidget(5, QFormLayout::FieldRole, pathLineEdit);

        blurKernalLabel = new QLabel(ImageViewerWidget);
        blurKernalLabel->setObjectName(QStringLiteral("blurKernalLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, blurKernalLabel);

        blurKernalSlider = new QSlider(ImageViewerWidget);
        blurKernalSlider->setObjectName(QStringLiteral("blurKernalSlider"));
        blurKernalSlider->setMinimum(0);
        blurKernalSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, blurKernalSlider);


        verticalLayout->addLayout(formLayout);


        retranslateUi(ImageViewerWidget);

        QMetaObject::connectSlotsByName(ImageViewerWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageViewerWidget)
    {
        ImageViewerWidget->setWindowTitle(QApplication::translate("ImageViewerWidget", "Image Viewer", 0));
        kernalSizeLabel->setText(QApplication::translate("ImageViewerWidget", "Kernal Size", 0));
        ratioLabel->setText(QApplication::translate("ImageViewerWidget", "Ratio", 0));
        lowThresholdLabel->setText(QApplication::translate("ImageViewerWidget", "Low Threshold", 0));
        loadButton->setText(QApplication::translate("ImageViewerWidget", "Load", 0));
        blurKernalLabel->setText(QApplication::translate("ImageViewerWidget", "Blur Kernal", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageViewerWidget: public Ui_ImageViewerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWERWIDGET_H
