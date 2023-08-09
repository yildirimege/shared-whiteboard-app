#ifndef DRAWINGCANVAS_H
#define DRAWINGCANVAS_H

#include <QWidget>
#include <QPixmap>
#include <QPoint>

class DrawingCanvas : public QWidget
{
    Q_OBJECT

public:
    explicit DrawingCanvas(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void drawLineTo(const QPoint &endPoint);

    QPixmap m_pixmap;
    QPoint m_lastPoint;
    bool m_isDrawing;
};

#endif // DRAWINGCANVAS_H
