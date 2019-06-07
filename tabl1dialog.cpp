#include "tabl1dialog.h"
#include "ui_tabl1dialog.h"
#include <fstream>

#include <QDebug>

tabl1Dialog::tabl1Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tabl1Dialog)
{
    ui->setupUi(this);


setWindowFlag(Qt::WindowContextHelpButtonHint, false);

int n, i = 0;
double q1, q5, q99, q95;
std::ifstream fin("criteria1.txt");

while (fin) {
    fin >> n >> q1 >> q5 >> q99 >> q95;

    int lastRow = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(lastRow);

    QTableWidgetItem *item = new QTableWidgetItem();
    QString str = QString::number(n);
    item->setText(QString("%1").arg(str));
    ui->tableWidget->setItem(i, 0, item);

    QTableWidgetItem *item1 = new QTableWidgetItem();
    str = QString::number(q1);
    item1->setText(QString("%1").arg(str));
    ui->tableWidget->setItem(i, 1, item1);

    QTableWidgetItem *item2 = new QTableWidgetItem();
    str = QString::number(q5);
    item2->setText(QString("%1").arg(str));
    ui->tableWidget->setItem(i, 2, item2);

    QTableWidgetItem *item3 = new QTableWidgetItem();
    str = QString::number(q99);
    item3->setText(QString("%1").arg(str));
    ui->tableWidget->setItem(i, 3, item3);

    QTableWidgetItem *item4 = new QTableWidgetItem();
    str = QString::number(q95);
    item4->setText(QString("%1").arg(str));
    ui->tableWidget->setItem(i, 4, item4);

    ++i;
}
int lastRow = ui->tableWidget->rowCount();
ui->tableWidget->removeRow(lastRow-1);
}



tabl1Dialog::~tabl1Dialog()
{
    delete ui;
}

