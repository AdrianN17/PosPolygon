#ifndef DATOS_H
#define DATOS_H

#include <QDialog>

namespace Ui {
class datos;
}

class datos : public QDialog
{
    Q_OBJECT

public:
    explicit datos(QWidget *parent = nullptr);
    ~datos();

    int get_x();
    int get_y();
    int get_w();
    int get_h();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::datos *ui;
};

#endif // DATOS_H
