#include <QApplication>
#include "mainwindow.h"
#include "cornerselectiondialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CornerSelectionDialog dialog;
    if(dialog.exec() == QDialog::Accepted) {
        MainWindow w;
        w.setPlayerCorner(dialog.selectedCorner());
        w.showFullScreen();
        return a.exec();
    }

    return 0;
}
