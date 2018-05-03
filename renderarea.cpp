#include "renderarea.h"
#include <QDebug>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent),
    pal(palette()),
    pen(QPen()),
    backgroundColor(Qt::black), arcColor(Qt::gray), pointsColor(Qt::yellow),
    mapX(100.f), mapY(100.f)
{
    pal.setColor(QPalette::Background, Qt::black);
    pen.setColor(arcColor);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    if (pen.color() != arcColor) {
        pen.setColor(arcColor);
    }
    QPainter painter(this);
    painter.setPen(pen);
    int width = geometry().width();
    int height = geometry().height();
    int halfWidth = width / 2;
    int halfHeight = height / 2;
    int xPos = width / 2 - mapX;
    int yPos = height / 2 - mapY;
    painter.drawEllipse(xPos, yPos, 2 * mapX, 2 * mapY);
    painter.drawLine(QPoint{0, halfHeight}, QPoint{width, halfHeight});
    painter.drawLine(QPoint{halfWidth, 0}, QPoint{halfWidth, height});

    pen.setColor(pointsColor);
    painter.setPen(pen);
    QPointF prev = {-123111, -123111};
    for (QPointF p: points) {
        p.rx() += halfWidth;
        p.ry() += halfHeight;
        if (prev != QPoint{-123111, -123111}) {
            painter.drawLine(prev, p);
        }
        painter.drawPoint(p);
        prev = p;
    }
}

void RenderArea::addPoint(QPointF point)
{
    qDebug() << QString("point(%1, %2)").arg(point.x()).arg(point.y());
    point.rx() *= mapX;
    point.ry() *= -1 * mapY;
    points.push_back(point);
    repaint();
}

void RenderArea::resetPoints()
{
    points.clear();
    repaint();
}

void RenderArea::changeColor(QColor color)
{
    pointsColor = color;
    repaint();
}

