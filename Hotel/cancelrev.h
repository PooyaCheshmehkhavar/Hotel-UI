#ifndef CANCELREV_H
#define CANCELREV_H

#include <QDialog>

namespace Ui {
class CancelRev;
}

class CancelRev : public QDialog
{
    Q_OBJECT

public:
    explicit CancelRev(QWidget *parent = nullptr);
    ~CancelRev();

private slots:
    void on_Cancelrev_clicked();

private:
    Ui::CancelRev *ui;
};

#endif
