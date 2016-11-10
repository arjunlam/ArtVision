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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imageviewer.h"

QT_BEGIN_NAMESPACE

class Ui_ImageViewerWidget
{
public:
    QVBoxLayout *verticalLayout;
    ImageViewer *imageViewer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *pathLineEdit;
    QPushButton *loadButton;

    void setupUi(QWidget *ImageViewerWidget)
    {
        if (ImageViewerWidget->objectName().isEmpty())
            ImageViewerWidget->setObjectName(QStringLiteral("ImageViewerWidget"));
        ImageViewerWidget->resize(580, 322);
        verticalLayout = new QVBoxLayout(ImageViewerWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        imageViewer = new ImageViewer(ImageViewerWidget);
        imageViewer->setObjectName(QStringLiteral("imageViewer"));
        imageViewer->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(imageViewer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pathLineEdit = new QLineEdit(ImageViewerWidget);
        pathLineEdit->setObjectName(QStringLiteral("pathLineEdit"));
        pathLineEdit->setEnabled(false);

        horizontalLayout->addWidget(pathLineEdit);

        loadButton = new QPushButton(ImageViewerWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        horizontalLayout->addWidget(loadButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ImageViewerWidget);

        QMetaObject::connectSlotsByName(ImageViewerWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageViewerWidget)
    {
        ImageViewerWidget->setWindowTitle(QApplication::translate("ImageViewerWidget", "Image Viewer", 0));
        loadButton->setText(QApplication::translate("ImageViewerWidget", "Load", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageViewerWidget: public Ui_ImageViewerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWERWIDGET_H
