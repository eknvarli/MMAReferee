#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QTime>
#include <QKeyEvent>

static const int ROUND_DURATION_SECONDS = 5 * 60; // 5:00

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pauseMatchButton->setEnabled(false);
    ui->endMatchButton->setEnabled(false);

    remainingSeconds = ROUND_DURATION_SECONDS;
    updateTimerDisplay();

    matchTimer = new QTimer(this);
    matchTimer->setInterval(1000);

    connect(matchTimer, &QTimer::timeout, this, &MainWindow::onTimerTick);

    connect(ui->startMatchButton, &QPushButton::clicked,
            this, &MainWindow::startMatch);

    connect(ui->pauseMatchButton, &QPushButton::clicked,
            this, &MainWindow::pauseMatch);

    connect(ui->endMatchButton, &QPushButton::clicked,
            this, &MainWindow::endMatch);

    connect(ui->addActionButton, &QPushButton::clicked,
            this, &MainWindow::addActionFromUI);

    connect(ui->clearActionsButton, &QPushButton::clicked,
            this, &MainWindow::clearActions);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPlayerCorner(CornerSelectionDialog::Corner corner)
{
    playerCorner = corner;

    if (corner == CornerSelectionDialog::Red) {
        ui->cornerLabel->setText("RED CORNER");
        ui->cornerLabel->setStyleSheet(
            "background-color:#8B0000;color:white;font-weight:800;font-size:48px;");
    } else {
        ui->cornerLabel->setText("BLUE CORNER");
        ui->cornerLabel->setStyleSheet(
            "background-color:#003366;color:white;font-weight:800;font-size:48px;");
    }
}

void MainWindow::startMatch()
{
    matchTimer->start();
    ui->startMatchButton->setEnabled(false);
    ui->pauseMatchButton->setEnabled(true);
    ui->endMatchButton->setEnabled(true);
}

void MainWindow::pauseMatch()
{
    matchTimer->stop();
    ui->startMatchButton->setEnabled(true);
    ui->pauseMatchButton->setEnabled(false);
}

void MainWindow::endMatch()
{
    matchTimer->stop();
    remainingSeconds = ROUND_DURATION_SECONDS;
    updateTimerDisplay();

    ui->startMatchButton->setEnabled(true);
    ui->pauseMatchButton->setEnabled(false);
    ui->endMatchButton->setEnabled(false);
}

void MainWindow::onTimerTick()
{
    if (remainingSeconds <= 0) {
        endMatch();
        return;
    }

    remainingSeconds--;
    updateTimerDisplay();
}

void MainWindow::updateTimerDisplay()
{
    QTime t(0, 0);
    t = t.addSecs(remainingSeconds);
    ui->timerDisplay->setText(t.toString("mm:ss"));
}

void MainWindow::addAction(const QString &action)
{
    QString prefix = (playerCorner == CornerSelectionDialog::Red)
    ? "[RED]"
    : "[BLUE]";

    ui->strikesList->addItem(prefix + " " + action);
}

void MainWindow::addActionFromUI()
{
    QString action = ui->actionTypeCombo->currentText();
    addAction(action);
}

void MainWindow::clearActions()
{
    ui->strikesList->clear();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (!matchTimer->isActive()) {
        QMainWindow::keyPressEvent(event);
        return;
    }

    switch (event->key()) {
    case Qt::Key_A:
        addAction("Jab");
        break;
    case Qt::Key_S:
        addAction("Cross");
        break;
    case Qt::Key_D:
        addAction("Hook");
        break;
    case Qt::Key_F:
        addAction("Uppercut");
        break;
    case Qt::Key_T:
        addAction("Takedown");
        break;
    case Qt::Key_K:
        addAction("Knockdown");
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}
