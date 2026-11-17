#ifndef MAKERESERVE_H
#define MAKERESERVE_H

#include <QDialog>

namespace Ui {
class makereserve;
}

class makereserve : public QDialog
{
    Q_OBJECT

public:
    explicit makereserve(QWidget *parent = nullptr);
    ~makereserve();

private slots:
    void on_saverev_clicked();

private:
    Ui::makereserve *ui;
};

#endif
