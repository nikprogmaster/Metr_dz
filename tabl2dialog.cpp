#include "tabl2dialog.h"
#include "ui_tabl2dialog.h"

#include <fstream>
#include <string>
#include <QDebug>

tabl2Dialog::tabl2Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tabl2Dialog)
{
    ui->setupUi(this);
    setWindowFlag(Qt::WindowContextHelpButtonHint, false);

    int m, i = 0;
    std::string n;
    double q1, q2, q5;
    std::ifstream fin("criteria2.txt");

    while (fin) {
        fin >> n >> m >> q1 >> q2 >> q5;

        int lastRow = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(lastRow);

        QTableWidgetItem *item = new QTableWidgetItem();
        QString str = QString::fromStdString(n);
        item->setText(QString("%1").arg(str));
        ui->tableWidget->setItem(i, 0, item);

        QTableWidgetItem *item1 = new QTableWidgetItem();
        str = QString::number(m);
        item1->setText(QString("%1").arg(str));
        ui->tableWidget->setItem(i, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem();
        str = QString::number(q1);
        item2->setText(QString("%1").arg(str));
        ui->tableWidget->setItem(i, 2, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem();
        str = QString::number(q2);
        item3->setText(QString("%1").arg(str));
        ui->tableWidget->setItem(i, 3, item3);

        QTableWidgetItem *item4 = new QTableWidgetItem();
        str = QString::number(q5);
        item4->setText(QString("%1").arg(str));
        ui->tableWidget->setItem(i, 4, item4);

        ++i;
    }
    int lastRow = ui->tableWidget->rowCount();
    ui->tableWidget->removeRow(lastRow-1);
    }


tabl2Dialog::~tabl2Dialog()
{
    delete ui;
}
