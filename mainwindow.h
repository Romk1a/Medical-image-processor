#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLineEdit>
#include <QColorDialog>
#include <QCheckBox>
#include <QPushButton>
#include <QTranslator>
#include <QComboBox>
#include <QWheelEvent>
#include <QStack>
#include <QShortcut>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private slots:
    void loadImage();
    void resetImage();
    void saveImage();
    void chooseFillColor();
    void changeLanguage(int index);
    void zoomIn();
    void zoomOut();
    void undo();
    void changeTheme(int index);
    void toggleNativeWidgets();

private:
    void updateViewScale();
    void applyTheme(int index);
    void restartApplication();
    void updateToolTips();

private:
    Ui::MainWindow *ui;
    QImage originalImage;
    QImage processedImage;
    QGraphicsScene *scene;
    QColor fillColor;
    bool allowBreaks;
    QTranslator translator;
    QStack<QImage> undoStack;
};

#endif // MAINWINDOW_H
