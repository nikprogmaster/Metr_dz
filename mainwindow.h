#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tabl1dialog.h"
#include "tabl2dialog.h"
#include "sample.h"
#include "cont.h"
#include "cont1.h"

#include <QDebug>

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_1_triggered();
    void on_action_2_triggered();
    void on_action_3_triggered();
    void clear_results();
    void update_tbl_data();
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_Count_clicked();

    void on_Report_clicked();

private:
    Ui::MainWindow *ui;
    tabl1Dialog *dlg_t1;
    tabl2Dialog *dlg_t2;
    Sample _sample;
    Cont1 tabl1;
    Cont tabl2;
    int q1, q2;
};

#endif // MAINWINDOW_H
