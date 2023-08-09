#include "UI/DrawingCanvas.h"

#include <QPainter>
#include <QMouseEvent>

DrawingCanvas::DrawingCanvas(QWidget *parent)
    : QWidget(parent), m_isDrawing(false)
{
    setAttribute(Qt::WA_StaticContents);
    m_pixmap = QPixmap(size());
    m_pixmap.fill(Qt::white);
}

void DrawingCanvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_pixmap);
}

void DrawingCanvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_lastPoint = event->pos();
        m_isDrawing = true;
    }
}

void DrawingCanvas::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDrawing && (event->buttons() & Qt::LeftButton)) {
        drawLineTo(event->pos());
    }
}

void DrawingCanvas::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && m_isDrawing) {
        drawLineTo(event->pos());
        m_isDrawing = false;
    }
}

void DrawingCanvas::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&m_pixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::black);
    painter.drawLine(m_lastPoint, endPoint);
    m_lastPoint = endPoint;
    update(); // Schedule a repaint
}
