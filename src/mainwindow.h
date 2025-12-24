#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include "cornerselectiondialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setPlayerCorner(CornerSelectionDialog::Corner corner);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void startMatch();
    void pauseMatch();
    void endMatch();
    void onTimerTick();
    void addActionFromUI();
    void clearActions();

private:
    Ui::MainWindow *ui;

    CornerSelectionDialog::Corner playerCorner;

    int remainingSeconds;
    QTimer *matchTimer;

    int redScore = 0;
    int blueScore = 0;

    void updateScore();
    void updateTimerDisplay();
    void addAction(const QString &action);
};

#endif // MAINWINDOW_H
