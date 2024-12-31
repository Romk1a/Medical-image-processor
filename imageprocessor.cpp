#include "imageprocessor.h"
#include <QQueue>
#include <QVector>
#include <QStack>

QStack<QImage> ImageProcessor::undoStack;
QStack<QImage> ImageProcessor::fillUndoStack;

void ImageProcessor::floodFill(QImage &image, int startX, int startY, int E, bool allowBreaks, const QColor &fillColor) {
    if (image.isNull()) return;

    // Сохраняем текущее состояние изображения в стек для заливки
    fillUndoStack.push(image.copy());

    // Получаем цвет начальной точки
    QColor startColor = image.pixelColor(startX, startY);
    int R1 = startColor.red();
    int G1 = startColor.green();
    int B1 = startColor.blue();

    if (!allowBreaks) {
        // Режим без разрывов: проверяем каждый пиксель
        for (int y = 0; y < image.height(); ++y) {
            for (int x = 0; x < image.width(); ++x) {
                QColor currentColor = image.pixelColor(x, y);
                int R2 = currentColor.red();
                int G2 = currentColor.green();
                int B2 = currentColor.blue();

                // Вычисляем цветовое расстояние
                int colorDistance = qAbs(R1 - R2) + qAbs(G1 - G2) + qAbs(B1 - B2);

                // Если расстояние меньше или равно E, заливаем пиксель
                if (colorDistance <= E) {
                    image.setPixelColor(x, y, fillColor);
                }
            }
        }
    } else {
        // Режим с разрывами: используем BFS
        QQueue<QPoint> queue;
        queue.enqueue(QPoint(startX, startY));

        QVector<QVector<bool>> visited(image.width(), QVector<bool>(image.height(), false));

        while (!queue.isEmpty()) {
            QPoint p = queue.dequeue();
            int x = p.x();
            int y = p.y();

            if (x < 0 || x >= image.width() || y < 0 || y >= image.height()) continue;
            if (visited[x][y]) continue;

            QColor currentColor = image.pixelColor(x, y);
            int R2 = currentColor.red();
            int G2 = currentColor.green();
            int B2 = currentColor.blue();

            // Вычисляем цветовое расстояние
            int colorDistance = qAbs(R1 - R2) + qAbs(G1 - G2) + qAbs(B1 - B2);

            // Если расстояние меньше или равно E, заливаем пиксель
            if (colorDistance <= E) {
                image.setPixelColor(x, y, fillColor);
                visited[x][y] = true;

                // Добавляем соседние пиксели в очередь
                queue.enqueue(QPoint(x + 1, y));
                queue.enqueue(QPoint(x - 1, y));
                queue.enqueue(QPoint(x, y + 1));
                queue.enqueue(QPoint(x, y - 1));
            }
        }
    }
}

void ImageProcessor::pushToUndoStack(const QImage &image) {
    undoStack.push(image);
}

QImage ImageProcessor::undo() {
    if (!fillUndoStack.isEmpty()) {
        // Возвращаем состояние изображения до последней заливки
        return fillUndoStack.pop();
    }
    return QImage();
}

void ImageProcessor::clearFillUndoStack() {
    fillUndoStack.clear();
}
