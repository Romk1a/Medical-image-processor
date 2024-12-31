#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QTranslator>

class SettingsManager {
public:
    static void changeLanguage(int index);

private:
    static QTranslator translator;
};

#endif // SETTINGSMANAGER_H
