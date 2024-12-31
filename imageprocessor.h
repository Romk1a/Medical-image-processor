#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QImage>
#include <QColor>
#include <QStack>

class ImageProcessor {
public:
    static void floodFill(QImage &image, int startX, int startY, int E, bool allowBreaks, const QColor &fillColor);
    static void pushToUndoStack(const QImage &image);
    static QImage undo();
    static void clearFillUndoStack();

private:
    static QStack<QImage> undoStack;
    static QStack<QImage> fillUndoStack;
};

#endif // IMAGEPROCESSOR_H
