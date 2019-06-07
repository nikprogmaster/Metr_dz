#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dlg_t1 = new tabl1Dialog(this);
    dlg_t2 = new tabl2Dialog(this);
    ui->Count->setEnabled(false);
    ui->Report->setEnabled(false);
    ui->tableWidget->setColumnWidth(0, 190);

    tabl1.filling1();
    tabl2.filing();
    q1=1;
    q2=2;

    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->Size->setReadOnly(true);
}


void MainWindow::on_action_1_triggered() {
    dlg_t1->show();
}

void MainWindow::on_action_2_triggered() {
    dlg_t2->show();
}


void MainWindow::update_tbl_data() {
    ui->tableWidget->setRowCount(0);

    for (auto i : _sample) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        int row = ui->tableWidget->rowCount() - 1;
        auto *item = new QTableWidgetItem(QString::number(i));
        ui->tableWidget->setItem(row, 0, item);
    }

    ui->Size->setText(QString::number(_sample.size()));
}

void MainWindow::clear_results() {
    ui->label_9->clear();
    ui->Count->setEnabled(false);
}


void MainWindow::on_action_3_triggered() {
    std::string filename = QFileDialog::getOpenFileName(this,
                               "Открыть файл выборки",
                               "",
                               "Все файлы (*)").toLocal8Bit().toStdString();

    if (filename == "")
        return;

    _sample.read_from_file(filename);
    update_tbl_data();
    clear_results();
    ui->Count->setEnabled(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_clicked()
{
    q1 = 1;
}

void MainWindow::on_radioButton_2_clicked()
{
    q1 = 5;
}

void MainWindow::on_radioButton_3_clicked()
{
    q2 = 1;
}

void MainWindow::on_radioButton_4_clicked()
{
    q2 = 2;
}

void MainWindow::on_radioButton_5_clicked()
{
    q2 = 5;
}

void MainWindow::on_Count_clicked()
{
    if (_sample.size() < 15 || _sample.size() > 50) {
        QMessageBox::critical(this, "Ошибка!", "Расчет возможен только при размере выборки от 15 до 50 значений.");
        return;
    }


    ui->lineEdit_2->setText(QString::number(_sample.mean()));
    ui->lineEdit_3->setText(QString::number(_sample.variance()));

    ui->Report->setEnabled(true);

    if (_sample.crit_1(tabl1, q1)&&_sample.crit_2(tabl2, q2)) {
        ui->label_9->setText("Результат измерений принадлежит нормальному распределению");
    } else {
        ui->label_9->setText("Результат измерений не принадлежит нормальному распределению");

}
}

void MainWindow::on_Report_clicked()
{
    std::string filename = QFileDialog::getSaveFileName(nullptr,
                                            "Сохранить результат работы программы",
                                            "",
                                            "Текст (*.txt)").toLocal8Bit().toStdString();

    if (filename == "")
        return;

    std::ofstream fout(filename);

    fout << "Среднее арифметическое, Xavg: " << ui->lineEdit_2->text().toStdString() << "\n";
    fout << "СКО, S: " << ui->lineEdit_3->text().toStdString() << "\n";
    fout << "Результат: " << ui->label_9->text().toStdString() << "\n";
}
