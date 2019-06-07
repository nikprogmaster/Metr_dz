#ifndef TABL1DIALOG_H
#define TABL1DIALOG_H

#include <QDialog>

namespace Ui {
class tabl1Dialog;
}

class tabl1Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit tabl1Dialog(QWidget *parent = nullptr);
    ~tabl1Dialog();

private:
    Ui::tabl1Dialog *ui;
};

#endif // TABL1DIALOG_H
