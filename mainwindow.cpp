#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <random>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    renderArea(new RenderArea(this))
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(renderArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addPointPushButton_clicked()
{
    std::default_random_engine en(std::random_device{}());

    float xPos = std::uniform_real_distribution<float> {-1.f, 1.f} (en);
    float range = sqrt(1 - pow(xPos, 2));
    float yPos = std::uniform_real_distribution<float> {-1 * range, range} (en);
    QPointF rndPos = {xPos, yPos};
    renderArea->addPoint(rndPos);
}

void MainWindow::on_resetPushButton_clicked()
{
    renderArea->resetPoints();
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QColor color;
    if (arg1 == "Yellow") {
        color = Qt::yellow;
    } else if (arg1 == "Black") {
        color = Qt::black;
    } else if (arg1 == "White") {
        color = Qt::white;
    } else if (arg1 == "Blue") {
        color = Qt::blue;
    } else if (arg1 == "Green") {
        color = Qt::green;
    } else if (arg1 == "Red") {
        color = Qt::red;
    } else if (arg1 == "Pink") {
        color = QColor(0xff, 0x14, 0x93);
    } else if (arg1 == "Cyan") {
        color = Qt::cyan;
    } else if (arg1 == "Purple") {
        color = QColor(0x80, 0, 0x80);
    }

    renderArea->changeColor(color);
}
