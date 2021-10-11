#include <QApplication>
#include <QStyleFactory>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	MainWindow window;
	window.show();
	a.setStyle(QStyleFactory::create("Fusion"));
    return QApplication::exec();
}
