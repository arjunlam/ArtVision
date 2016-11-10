#include <QApplication>

#include "imageviewerwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageViewerWidget w;
    w.show();
    return a.exec();
}
