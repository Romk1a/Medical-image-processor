#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imageprocessor.h"
#include "settingsmanager.h"
#include "themes.h"
#include <QFileDialog>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QApplication>
#include <QWheelEvent>
#include <QMessageBox>
#include <QSettings>

extern bool useNativeWidgets; // Глобальная переменная для хранения режима адаптации

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Инициализация сцены и отображения изображения
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    // Установка начального цвета заливки
    fillColor = QColor(255, 0, 0); // Красный цвет по умолчанию

    // Установка флага для типа заливки
    allowBreaks = false; // Сплошная заливка по умолчанию

    // Подключение сигналов и слотов
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetImage);
    connect(ui->colorButton, &QPushButton::clicked, this, &MainWindow::chooseFillColor);
    connect(ui->zoomInButton, &QPushButton::clicked, this, &MainWindow::zoomIn);
    connect(ui->zoomOutButton, &QPushButton::clicked, this, &MainWindow::zoomOut);
    connect(ui->undoButton, &QPushButton::clicked, this, &MainWindow::undo);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::loadImage); // Подключаем действие "Open"
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveImage); // Подключаем действие "Save"
    connect(ui->actionEnglish, &QAction::triggered, this, [this]() { changeLanguage(0); }); // English
    connect(ui->actionRussian, &QAction::triggered, this, [this]() { changeLanguage(1); }); // Русский
    connect(ui->actionGerman, &QAction::triggered, this, [this]() { changeLanguage(2); }); // Немецкий
    connect(ui->actionFrench, &QAction::triggered, this, [this]() { changeLanguage(3); }); // Французский
    connect(ui->actionChinese, &QAction::triggered, this, [this]() { changeLanguage(4); }); // Китайский
    connect(ui->actionJapanese, &QAction::triggered, this, [this]() { changeLanguage(5); }); // Японский
    connect(ui->actionSpanish, &QAction::triggered, this, [this]() { changeLanguage(6); }); // Испанский
    connect(ui->actionLightTheme, &QAction::triggered, this, [this]() { changeTheme(0); }); // Light theme
    connect(ui->actionDarkTheme, &QAction::triggered, this, [this]() { changeTheme(1); }); // Dark theme
    connect(ui->actionToggleNativeWidgets, &QAction::triggered, this, &MainWindow::toggleNativeWidgets); // Подключаем действие "OS Adaptation"

    // Установка фильтра событий для обработки кликов
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->installEventFilter(this);

    // Установка горячих клавиш
    ui->actionOpen->setShortcut(QKeySequence::Open); // Ctrl+O
    ui->actionSave->setShortcut(QKeySequence::Save); // Ctrl+S
    QShortcut *undoShortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
    connect(undoShortcut, &QShortcut::activated, this, &MainWindow::undo);

    // Установка языка по умолчанию
    QLocale systemLocale = QLocale::system();
    if (systemLocale.language() == QLocale::Russian) {
        changeLanguage(1); // Устанавливаем русский язык
    } else if (systemLocale.language() == QLocale::German) {
        changeLanguage(2); // Устанавливаем немецкий язык
    } else if (systemLocale.language() == QLocale::French) {
        changeLanguage(3); // Устанавливаем французский язык
    } else if (systemLocale.language() == QLocale::Chinese) {
        changeLanguage(4); // Устанавливаем китайский язык
    } else if (systemLocale.language() == QLocale::Japanese) {
        changeLanguage(5); // Устанавливаем японский язык
    } else if (systemLocale.language() == QLocale::Spanish) {
        changeLanguage(6); // Устанавливаем испанский язык
    } else {
        changeLanguage(0); // Устанавливаем английский язык по умолчанию
    }

    applyTheme(0); // Устанавливаем светлую тему по умолчанию

    // Устанавливаем иконки для кнопок
    ui->zoomInButton->setIcon(QIcon(":/icons/icons/zoom_in.svg"));
    ui->zoomOutButton->setIcon(QIcon(":/icons/icons/zoom_out.svg"));
    ui->undoButton->setIcon(QIcon(":/icons/icons/undo.svg"));
    ui->resetButton->setIcon(QIcon(":/icons/icons/reset.svg"));
    ui->colorButton->setIcon(QIcon(":/icons/icons/color.svg"));
    ui->breaksCheckBox->setIcon(QIcon(":/icons/icons/break.svg"));
    ui->menuFile->setIcon(QIcon(":/icons/icons/file.svg"));
    ui->menuSettings->setIcon(QIcon(":/icons/icons/settings.svg"));


    // Установка подсказок для кнопок и элементов управления
    ui->zoomInButton->setToolTip(tr("Zoom in the image"));
    ui->zoomOutButton->setToolTip(tr("Zoom out the image"));
    ui->undoButton->setToolTip(tr("Undo the last action"));
    ui->resetButton->setToolTip(tr("Reset the image to its original state"));
    ui->colorButton->setToolTip(tr("Choose the fill color"));
    ui->EInput->setToolTip(tr("Enter the tolerance value (E) for flood fill"));
    ui->breaksCheckBox->setToolTip(tr("Allow breaks in flood fill"));

    // Инициализация состояния чекбокса "OS Adaptation"
    ui->actionToggleNativeWidgets->setChecked(useNativeWidgets);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::toggleNativeWidgets() {
    // Переключаем режим адаптации
    useNativeWidgets = !useNativeWidgets;

    // Устанавливаем состояние чекбокса в зависимости от значения useNativeWidgets
    ui->actionToggleNativeWidgets->setChecked(useNativeWidgets);

    // Сохраняем состояние адаптации в QSettings
    QSettings settings("MyCompany", "MyApp");
    settings.setValue("useNativeWidgets", useNativeWidgets);

    // Уведомляем пользователя о необходимости перезапуска
    QMessageBox::information(this, tr("Changes will take effect"), tr("Changes will take effect only after restarting the application."));
}


void MainWindow::loadImage() {
    // Открываем диалог выбора файла
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (filePath.isEmpty()) return;

    // Сбрасываем масштабирование и прокрутку QGraphicsView
    ui->graphicsView->resetTransform();
    ui->graphicsView->setSceneRect(QRectF());
    ui->graphicsView->centerOn(0, 0);

    // Загружаем изображение
    originalImage = QImage(filePath);
    if (originalImage.isNull()) {
        qWarning("Failed to load image.");
        return;
    }

    // Создаем копию для обработки
    processedImage = originalImage.copy();

    // Очищаем стек отмены заливки для новой картинки
    ImageProcessor::clearFillUndoStack();

    // Отображаем изображение
    scene->clear();
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(processedImage));
    scene->addItem(item);

    // Устанавливаем размер сцены равным размеру изображения
    scene->setSceneRect(item->boundingRect());

    // Масштабируем изображение, чтобы оно вписывалось в окно
    updateViewScale();
}

void MainWindow::resetImage() {
    // Восстанавливаем оригинальное изображение
    processedImage = originalImage.copy();
    scene->clear();
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(processedImage));
    scene->addItem(item);

    // Масштабируем изображение, чтобы оно вписывалось в окно
    updateViewScale();
}

void MainWindow::saveImage() {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Image Files (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (filePath.isEmpty()) return;

    // Определяем формат файла по расширению
    QString format = "PNG"; // По умолчанию PNG
    if (filePath.endsWith(".jpg", Qt::CaseInsensitive) || filePath.endsWith(".jpeg", Qt::CaseInsensitive)) {
        format = "JPEG";
    } else if (filePath.endsWith(".bmp", Qt::CaseInsensitive)) {
        format = "BMP";
    } else if (filePath.endsWith(".gif", Qt::CaseInsensitive)) {
        format = "GIF";
    }

    // Сохраняем изображение в выбранном формате
    if (!processedImage.save(filePath, format.toStdString().c_str())) {
        qWarning("Failed to save image.");
    }
}

void MainWindow::chooseFillColor() {
    // Открываем диалог выбора цвета
    QColor selectedColor = QColorDialog::getColor(fillColor, this, tr("Choose Fill Color"));
    if (selectedColor.isValid()) {
        fillColor = selectedColor;
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->graphicsView) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if (mouseEvent->button() == Qt::LeftButton) {
                // Получаем координаты клика
                QPointF pos = ui->graphicsView->mapToScene(mouseEvent->pos());
                int x = static_cast<int>(pos.x());
                int y = static_cast<int>(pos.y());

                // Получаем значение E
                bool ok;
                int E = ui->EInput->text().toInt(&ok);

                // Проверяем корректность ввода E
                if (!ok || E < 0 || E > 765) {
                    QMessageBox::warning(this, tr("Invalid E value"), tr("E value should be a positive integer between 0 and 765."));
                    return false; // Прерываем выполнение
                }

                // Получаем тип заливки
                allowBreaks = ui->breaksCheckBox->isChecked();

                // Запускаем алгоритм заливки
                ImageProcessor::floodFill(processedImage, x, y, E, allowBreaks, fillColor);

                // Обновляем изображение без сброса масштаба
                scene->clear();
                QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(processedImage));
                scene->addItem(item);

                return true;
            }
        } else if (event->type() == QEvent::Wheel) {
            wheelEvent(static_cast<QWheelEvent*>(event)); // Передаем событие в метод wheelEvent
            return true;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    updateViewScale();
}

void MainWindow::updateViewScale() {
    if (!scene->items().isEmpty()) {
        ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
    }
}

void MainWindow::changeLanguage(int index) {
    SettingsManager::changeLanguage(index);
    ui->retranslateUi(this); // Перевод интерфейса
    updateToolTips(); // Обновляем подсказки
}

void MainWindow::zoomIn() {
    ui->graphicsView->scale(1.2, 1.2); // Увеличиваем масштаб на 20%
}

void MainWindow::zoomOut() {
    ui->graphicsView->scale(0.8, 0.8); // Уменьшаем масштаб на 20%
}

void MainWindow::wheelEvent(QWheelEvent *event) {
    if (event->modifiers() & Qt::ControlModifier) { // Если зажат Ctrl, масштабируем
        if (event->angleDelta().y() > 0) {
            zoomIn();
        } else {
            zoomOut();
        }
        event->accept();
    } else {
        QMainWindow::wheelEvent(event);
    }
}

void MainWindow::undo() {
    // Используем метод ImageProcessor::undo() для получения предыдущего состояния изображения
    QImage previousImage = ImageProcessor::undo();

    if (previousImage.isNull()) {
        qWarning("Nothing to undo.");
        return;
    }

    // Восстанавливаем предыдущее состояние
    processedImage = previousImage;

    // Обновляем изображение на сцене
    scene->clear();
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(processedImage));
    scene->addItem(item);

    // Не сбрасываем масштаб, оставляем текущий
}

void MainWindow::changeTheme(int index) {
    applyTheme(index);
}

void MainWindow::applyTheme(int index) {
    Themes::applyTheme(index);
}

void MainWindow::updateToolTips() {
    ui->zoomInButton->setToolTip(tr("Zoom in the image"));
    ui->zoomOutButton->setToolTip(tr("Zoom out the image"));
    ui->undoButton->setToolTip(tr("Undo the last action"));
    ui->resetButton->setToolTip(tr("Reset the image to its original state"));
    ui->colorButton->setToolTip(tr("Choose the fill color"));
    ui->EInput->setToolTip(tr("Enter the tolerance value (E) for flood fill"));
    ui->breaksCheckBox->setToolTip(tr("Allow breaks in flood fill"));
}
