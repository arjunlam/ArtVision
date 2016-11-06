#ifndef IMAGEVIEWERWIDGET_H
#define IMAGEVIEWERWIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class ImageViewerWidget;
}

class ImageViewerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageViewerWidget(QWidget *parent = nullptr);
    ~ImageViewerWidget();

public slots:
    void onLoadButtonClicked();

    // MEMBERS
protected:
    Ui::ImageViewerWidget *ui;
    QString imageDirectory;
};

#endif // IMAGEVIEWERWIDGET_H
