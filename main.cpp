#include <QApplication>
#include <QSettings>
#include "mainwindow.h"

bool useNativeWidgets = false; // Глобальная переменная для хранения режима адаптации

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Загружаем состояние адаптации из QSettings
    QSettings settings("MyCompany", "MyApp");
    useNativeWidgets = settings.value("useNativeWidgets", false).toBool();

    // Устанавливаем атрибуты в зависимости от значения useNativeWidgets
    if (useNativeWidgets) {
        QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar, false);
        QCoreApplication::setAttribute(Qt::AA_DontUseNativeDialogs, false);
        QCoreApplication::setAttribute(Qt::AA_DontCreateNativeWidgetSiblings, false);
    } else {
        QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);
        QCoreApplication::setAttribute(Qt::AA_DontUseNativeDialogs);
        QCoreApplication::setAttribute(Qt::AA_DontCreateNativeWidgetSiblings);
    }

    MainWindow w;
    w.show();
    return a.exec();
}
