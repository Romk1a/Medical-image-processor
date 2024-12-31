QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    imageprocessor.cpp \
    main.cpp \
    mainwindow.cpp \
    settingsmanager.cpp \
    themes.cpp

HEADERS += \
    imageprocessor.h \
    mainwindow.h \
    settingsmanager.h \
    themes.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

TRANSLATIONS += \
    files_translations/var_29_de_DE.ts \
    files_translations/var_29_en_US.ts \
    files_translations/var_29_es_ES.ts \
    files_translations/var_29_fr_FR.ts \
    files_translations/var_29_ja_JP.ts \
    files_translations/var_29_ru_RU.ts \
    files_translations/var_29_zh_CN.ts

DISTFILES += \
    icons/break.svg \
    icons/color.svg \
    icons/reset.svg \
    icons/undo.svg \
    icons/zoom_in.svg \
    icons/zoom_out.svg

RESOURCES += \
    myapp.qrc
