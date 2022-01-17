#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gscene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow { parent }
    , ui { new Ui::MainWindow }
{
    ui->setupUi(this);
    mScene = new GScene(this);
    ui->graphicsView->setScene(mScene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
