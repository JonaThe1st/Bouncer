#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Scene(this);
    scene->setSceneRect(0, -700, 500, 800);

    scene->addLine(0, 0, 500, 0, QPen(Qt::blue));
    scene->addLine(250, 100, 250, -700, QPen(Qt::blue));

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    scene->keyPressed(event);
    qDebug() << "Key was pressed with code: " << event->text();
    QWidget::keyPressEvent(event);
}


void MainWindow::on_pushButton_clicked()
{
    scene->nextState();
}
