#include "extra.h"
#include "ui_extra.h"

extra::extra(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::extra)
{
    ui->setupUi(this);
    insertar_colores(ui->combo1);
    insertar_colores(ui->combo2);
    insertar_colores(ui->combo3);

}

extra::~extra()
{
    delete ui;
}

void extra::on_checkBox_stateChanged(int arg1)
{
    if(arg1==0)
    {
        emit enviar_checkbox(false);
    }
    else
    {
        emit enviar_checkbox(true);
    }
}

void extra::on_combo1_currentIndexChanged(int index)
{
    emit enviar_color(0,get_color(index));
}

void extra::on_combo2_currentIndexChanged(int index)
{
    emit enviar_color(1,get_color(index));
}

void extra::on_combo3_currentIndexChanged(int index)
{
    emit enviar_color(2,get_color(index));
}

void extra::insertar_colores(QComboBox *combo)
{
    combo->addItem("rojo");
    combo->addItem("gris");
    combo->addItem("verde");
    combo->addItem("azul");
    combo->addItem("negro");
}

QColor extra::get_color(int index)
{
    QColor color;

    switch(index)
    {
        case 0:
            color = Qt::red;
            break;
        case 1:
            color = Qt::gray;
            break;
        case 2:
            color = Qt::green;
            break;
        case 3:
            color = Qt::blue;
            break;
        case 4:
            color = Qt::black;
            break;
    }

    return color;
}

void extra::on_spinner_tamano_valueChanged(int arg1)
{
    emit enviar_radio(arg1);
}
