#include "datos.h"
#include "ui_datos.h"

datos::datos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::datos)
{
    ui->setupUi(this);
}

datos::~datos()
{
    delete ui;
}

void datos::on_buttonBox_accepted()
{

}

int datos::get_x()
{
    return this->ui->txt_x->text().toInt();
}

int datos::get_y()
{
    return this->ui->txt_y->text().toInt();
}

int datos::get_w()
{
    return this->ui->txt_w->text().toInt();
}

int datos::get_h()
{
    return this->ui->txt_h->text().toInt();
}
