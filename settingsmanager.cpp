#include "settingsmanager.h"
#include <QApplication>
#include <QDebug>

QTranslator SettingsManager::translator;

void SettingsManager::changeLanguage(int index) {
    // Удаляем текущий переводчик
    qApp->removeTranslator(&translator);

    // Загружаем новый перевод в зависимости от выбранного языка
    bool loaded = false;
    if (index == 0) { // Английский язык
        loaded = translator.load(":/translation/files_translations/var_29_en_US.qm");
    } else if (index == 1) { // Русский язык
        loaded = translator.load(":/translation/files_translations/var_29_ru_RU.qm");
    } else if (index == 2) { // Немецкий язык
        loaded = translator.load(":/translation/files_translations/var_29_de_DE.qm");
    } else if (index == 3) { // Французский язык
        loaded = translator.load(":/translation/files_translations/var_29_fr_FR.qm");
    } else if (index == 4) { // Китайский язык
        loaded = translator.load(":/translation/files_translations/var_29_zh_CN.qm");
    } else if (index == 5) { // Японский язык
        loaded = translator.load(":/translation/files_translations/var_29_ja_JP.qm");
    } else if (index == 6) { // Испанский язык
        loaded = translator.load(":/translation/files_translations/var_29_es_ES.qm");
    }

    if (!loaded) {
        qWarning() << "Failed to load translation file!";
        return; // Если файл не загружен, выходим из функции
    }

    // Устанавливаем новый переводчик
    qApp->installTranslator(&translator);
}
