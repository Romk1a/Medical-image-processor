#include "themes.h"
#include <QApplication>

void Themes::applyTheme(int index) {

        QString styleSheet;

        if (index == 0) { // Light theme
            styleSheet = R"(
            QWidget {
                background-color: #f0f0f0; /* Светлый фон */
                color: #333333; /* Темный текст */
                font-family: "Arial";
                font-size: 14px;
            }

            QPushButton {
                background-color: #8bc34a; /* Светло-зеленый цвет */
                color: white; /* Белый текст */
                border: none;
                border-radius: 15px; /* Скругленные углы */
                padding: 10px 20px;
                font-size: 14px;
                font-weight: bold;
                text-transform: uppercase;
            }

            QPushButton:hover {
                background-color: #7cb342; /* Цвет при наведении */
            }

            QPushButton:pressed {
                background-color: #689f38; /* Цвет при нажатии */
            }

            QLabel {
                color: #333333; /* Темный текст */
                font-size: 16px;
                font-weight: bold;
            }

            QLineEdit {
                background-color: #ffffff; /* Белый фон */
                border: 1px solid #cccccc;
                border-radius: 5px;
                padding: 5px 10px;
                font-size: 14px;
            }

            QLineEdit:focus {
                border: 1px solid #8bc34a; /* Светло-зеленый цвет при фокусе */
            }

            QCheckBox {
                color: #333333; /* Темный текст */
                font-size: 14px;
            }

            QCheckBox::indicator {
                width: 20px;
                height: 20px;
            }

            QCheckBox::indicator:checked {
                background-color: #8bc34a; /* Светло-зеленый цвет при выборе */
            }

            QMenuBar {
                background-color: #8bc34a; /* Светло-зеленый цвет */
                color: white; /* Белый текст */
            }

            QMenuBar::item:selected {
                background-color: #7cb342; /* Цвет при наведении */
            }

            QMenu {
                background-color: #ffffff; /* Белый фон */
                color: #333333; /* Темный текст */
                border: 1px solid #cccccc;
            }

            QMenu::item:selected {
                background-color: #8bc34a; /* Светло-зеленый цвет при наведении */
                color: white; /* Белый текст */
            }
            QCheckBox {
                background-color: #8bc34a; /* Светло-зеленый цвет */
                color: white; /* Белый текст */
                border: none;
                border-radius: 15px; /* Скругленные углы */
                padding: 10px 20px;
                font-size: 14px;
                font-weight: bold;
                text-transform: uppercase;
            }

            QCheckBox::indicator {
                width: 0px; /* Скрываем стандартный индикатор */
                height: 0px;
            }

            QCheckBox:hover {
                background-color: #7cb342; /* Цвет при наведении */
            }

            QCheckBox:checked {
                background-color: #cddc39; /* Светло-желтый цвет, когда разрывы разрешены */
            }

            QCheckBox:checked:hover {
                background-color: #c0ca33; /* Цвет при наведении на выбранную кнопку */
            }

            QCheckBox:checked:pressed {
                background-color: #afb42b; /* Цвет при нажатии на выбранную кнопку */
            }

        )";
        } else { // Dark theme
            styleSheet = R"(
            QWidget {
                background-color: #2e2e2e; /* Тёмный фон */
                color: #f0f0f0; /* Светлый текст */
                font-family: "Arial";
                font-size: 14px;
            }

            QPushButton {
                background-color: #4caf50; /* Зелёный цвет */
                color: white; /* Белый текст */
                border: none;
                border-radius: 15px; /* Скругленные углы */
                padding: 10px 20px;
                font-size: 14px;
                font-weight: bold;
                text-transform: uppercase;
            }

            QPushButton:hover {
                background-color: #43a047; /* Цвет при наведении */
            }

            QPushButton:pressed {
                background-color: #388e3c; /* Цвет при нажатии */
            }

            QLabel {
                color: #f0f0f0; /* Светлый текст */
                font-size: 16px;
                font-weight: bold;
            }

            QLineEdit {
                background-color: #424242; /* Тёмный фон */
                border: 1px solid #616161;
                border-radius: 5px;
                padding: 5px 10px;
                font-size: 14px;
                color: #f0f0f0; /* Светлый текст */
            }

            QLineEdit:focus {
                border: 1px solid #4caf50; /* Зелёный цвет при фокусе */
            }

            QCheckBox {
                color: #f0f0f0; /* Светлый текст */
                font-size: 14px;
            }

            QCheckBox::indicator {
                width: 20px;
                height: 20px;
                background-color: #424242; /* Тёмный фон */
            }

            QCheckBox::indicator:checked {
                background-color: #4caf50; /* Зелёный цвет при выборе */
            }

            QMenuBar {
                background-color: #4caf50; /* Зелёный цвет */
                color: white; /* Белый текст */
            }

            QMenuBar::item:selected {
                background-color: #43a047; /* Цвет при наведении */
            }

            QMenu {
                background-color: #424242; /* Тёмный фон */
                color: #f0f0f0; /* Светлый текст */
                border: 1px solid #616161;
            }

            QMenu::item:selected {
                background-color: #4caf50; /* Зелёный цвет при наведении */
                color: white; /* Белый текст */
            }
            QCheckBox {
                background-color: #4caf50; /* Зелёный цвет */
                color: white; /* Белый текст */
                border: none;
                border-radius: 15px; /* Скругленные углы */
                padding: 10px 20px;
                font-size: 14px;
                font-weight: bold;
                text-transform: uppercase;
            }

            QCheckBox::indicator {
                width: 0px; /* Скрываем стандартный индикатор */
                height: 0px;
            }

            QCheckBox:hover {
                background-color: #43a047; /* Цвет при наведении */
            }

            QCheckBox:checked {
                background-color: #cddc39; /* Светло-желтый цвет, когда разрывы разрешены */
            }

            QCheckBox:checked:hover {
                background-color: #c0ca33; /* Цвет при наведении на выбранную кнопку */
            }

            QCheckBox:checked:pressed {
                background-color: #afb42b; /* Цвет при нажатии на выбранную кнопку */
            }
        )";
        }

        // Применяем стили к приложению
        qApp->setStyleSheet(styleSheet);

    }
