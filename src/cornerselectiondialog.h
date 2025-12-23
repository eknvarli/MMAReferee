#ifndef CORNERSELECTIONDIALOG_H
#define CORNERSELECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class CornerSelectionDialog;
}

class CornerSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CornerSelectionDialog(QWidget *parent = nullptr);
    ~CornerSelectionDialog();

    enum Corner { Red, Blue };
    Corner selectedCorner() const;

private slots:
    void on_redButton_clicked();
    void on_blueButton_clicked();

private:
    Ui::CornerSelectionDialog *ui;
    Corner m_selectedCorner;
};

#endif // CORNERSELECTIONDIALOG_H
