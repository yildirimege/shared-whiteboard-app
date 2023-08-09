#ifndef DRAWINGMANAGER_H
#define DRAWINGMANAGER_H

#include "UI/DrawingCanvas.h"

class DrawingManager {
public:
    DrawingManager(DrawingCanvas& canvas);

    void draw();
private:
    DrawingCanvas& m_canvas;
};

#endif // DRAWINGMANAGER_H
