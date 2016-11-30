/********************************************************************************
** Form generated from reading UI file 'edgedetectionwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDGEDETECTIONWIDGET_H
#define UI_EDGEDETECTIONWIDGET_H

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
#include "src/imageviewerwidget.h"

QT_BEGIN_NAMESPACE

class Ui_EdgeDetectionWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    ImageViewerWidget *imageViewer;
    ImageViewerWidget *edgeViewer;
    ImageViewerWidget *intersectionViewer;
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

    void setupUi(QWidget *EdgeDetectionWidget)
    {
        if (EdgeDetectionWidget->objectName().isEmpty())
            EdgeDetectionWidget->setObjectName(QStringLiteral("EdgeDetectionWidget"));
        EdgeDetectionWidget->resize(580, 322);
        verticalLayout = new QVBoxLayout(EdgeDetectionWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        imageViewer = new ImageViewerWidget(EdgeDetectionWidget);
        imageViewer->setObjectName(QStringLiteral("imageViewer"));
        imageViewer->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(imageViewer);

        edgeViewer = new ImageViewerWidget(EdgeDetectionWidget);
        edgeViewer->setObjectName(QStringLiteral("edgeViewer"));

        horizontalLayout_2->addWidget(edgeViewer);

        intersectionViewer = new ImageViewerWidget(EdgeDetectionWidget);
        intersectionViewer->setObjectName(QStringLiteral("intersectionViewer"));

        horizontalLayout_2->addWidget(intersectionViewer);


        verticalLayout->addLayout(horizontalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        kernalSizeLabel = new QLabel(EdgeDetectionWidget);
        kernalSizeLabel->setObjectName(QStringLiteral("kernalSizeLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, kernalSizeLabel);

        kernalSizeSlider = new QSlider(EdgeDetectionWidget);
        kernalSizeSlider->setObjectName(QStringLiteral("kernalSizeSlider"));
        kernalSizeSlider->setMinimum(1);
        kernalSizeSlider->setMaximum(3);
        kernalSizeSlider->setSingleStep(1);
        kernalSizeSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, kernalSizeSlider);

        ratioLabel = new QLabel(EdgeDetectionWidget);
        ratioLabel->setObjectName(QStringLiteral("ratioLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, ratioLabel);

        ratioSlider = new QSlider(EdgeDetectionWidget);
        ratioSlider->setObjectName(QStringLiteral("ratioSlider"));
        ratioSlider->setMinimum(0);
        ratioSlider->setMaximum(100);
        ratioSlider->setSingleStep(1);
        ratioSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(3, QFormLayout::FieldRole, ratioSlider);

        lowThresholdLabel = new QLabel(EdgeDetectionWidget);
        lowThresholdLabel->setObjectName(QStringLiteral("lowThresholdLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lowThresholdLabel);

        lowThresholdSlider = new QSlider(EdgeDetectionWidget);
        lowThresholdSlider->setObjectName(QStringLiteral("lowThresholdSlider"));
        lowThresholdSlider->setMinimum(0);
        lowThresholdSlider->setMaximum(100);
        lowThresholdSlider->setSingleStep(1);
        lowThresholdSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(4, QFormLayout::FieldRole, lowThresholdSlider);

        loadButton = new QPushButton(EdgeDetectionWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        formLayout->setWidget(5, QFormLayout::LabelRole, loadButton);

        pathLineEdit = new QLineEdit(EdgeDetectionWidget);
        pathLineEdit->setObjectName(QStringLiteral("pathLineEdit"));
        pathLineEdit->setEnabled(false);

        formLayout->setWidget(5, QFormLayout::FieldRole, pathLineEdit);

        blurKernalLabel = new QLabel(EdgeDetectionWidget);
        blurKernalLabel->setObjectName(QStringLiteral("blurKernalLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, blurKernalLabel);

        blurKernalSlider = new QSlider(EdgeDetectionWidget);
        blurKernalSlider->setObjectName(QStringLiteral("blurKernalSlider"));
        blurKernalSlider->setMinimum(0);
        blurKernalSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, blurKernalSlider);


        verticalLayout->addLayout(formLayout);


        retranslateUi(EdgeDetectionWidget);

        QMetaObject::connectSlotsByName(EdgeDetectionWidget);
    } // setupUi

    void retranslateUi(QWidget *EdgeDetectionWidget)
    {
        EdgeDetectionWidget->setWindowTitle(QApplication::translate("EdgeDetectionWidget", "Image Viewer", 0));
        kernalSizeLabel->setText(QApplication::translate("EdgeDetectionWidget", "Kernal Size", 0));
        ratioLabel->setText(QApplication::translate("EdgeDetectionWidget", "Ratio", 0));
        lowThresholdLabel->setText(QApplication::translate("EdgeDetectionWidget", "Low Threshold", 0));
        loadButton->setText(QApplication::translate("EdgeDetectionWidget", "Load", 0));
        blurKernalLabel->setText(QApplication::translate("EdgeDetectionWidget", "Blur Kernal", 0));
    } // retranslateUi

};

namespace Ui {
    class EdgeDetectionWidget: public Ui_EdgeDetectionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDGEDETECTIONWIDGET_H
