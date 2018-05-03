#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QPointF>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void addPoint(QPointF point);
    void resetPoints();
    void changeColor(QColor color);

private:
    QPalette pal;
    QPen pen;
    QColor backgroundColor;
    QColor arcColor;
    QColor pointsColor;
    QVector<QPointF> points;
    float mapX;
    float mapY;
};

#endif // RENDERAREA_H
