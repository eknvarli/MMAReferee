#include "cornerselectiondialog.h"
#include "ui_cornerselectiondialog.h"

CornerSelectionDialog::CornerSelectionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CornerSelectionDialog)
{
    ui->setupUi(this);
}

CornerSelectionDialog::~CornerSelectionDialog()
{
    delete ui;
}

CornerSelectionDialog::Corner CornerSelectionDialog::selectedCorner() const
{
    return m_selectedCorner;
}

void CornerSelectionDialog::on_redButton_clicked()
{
    m_selectedCorner = Red;
    accept();
}

void CornerSelectionDialog::on_blueButton_clicked()
{
    m_selectedCorner = Blue;
    accept();
}
