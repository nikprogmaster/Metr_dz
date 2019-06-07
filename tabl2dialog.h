#ifndef TABL2DIALOG_H
#define TABL2DIALOG_H

#include <QDialog>

namespace Ui {
class tabl2Dialog;
}

class tabl2Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit tabl2Dialog(QWidget *parent = nullptr);
    ~tabl2Dialog();

private:
    Ui::tabl2Dialog *ui;
};

#endif // TABL2DIALOG_H
