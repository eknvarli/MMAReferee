#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPlayerCorner(CornerSelectionDialog::Corner corner)
{
    playerCorner = corner;

    if (playerCorner == CornerSelectionDialog::Red) {
        ui->cornerLabel->setText("Selected Corner: Red");
    }
    else if (playerCorner == CornerSelectionDialog::Blue) {
        ui->cornerLabel->setText("Selected Corner: Blue");
    } else {
        ui->cornerLabel->setText("Selected Corner: None");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_A:
        if(playerCorner == CornerSelectionDialog::Red)
            redScore++;
        else
            blueScore++;
        break;
    case Qt::Key_B:
        if(playerCorner == CornerSelectionDialog::Red)
            redScore++;
        else
            blueScore++;
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
    updateScore();
}

void MainWindow::updateScore()
{

}
