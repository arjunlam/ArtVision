#include <QApplication>

#include "imageviewerwidget.h"
#include "edgedetectionwidget.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    EdgeDetectionWidget w;
    w.show();
    return a.exec();
}
