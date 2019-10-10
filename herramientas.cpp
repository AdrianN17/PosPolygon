#include "herramientas.h"
#include "ui_herramientas.h"

herramientas::herramientas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::herramientas)
{
    const int max=450;

    ui->setupUi(this);

    /*ui->txt_centrox->setValidator( new QDoubleValidator(0, max, 2, this) );
    ui->txt_centroy->setValidator( new QDoubleValidator(0, max, 2, this) );

    ui->txt_puntox->setValidator( new QDoubleValidator(0, max, 2, this) );
    ui->txt_puntoy->setValidator( new QDoubleValidator(0, max, 2, this) );*/
}

herramientas::~herramientas()
{
    delete ui;
}

void herramientas::editar_centros(QVector2D centro)
{
    float x= centro.x();
    float y= centro.y();


    ui->txt_centrox->setText(QString::number(x));
    ui->txt_centroy->setText(QString::number(y));
}

void herramientas::on_btn_guardar_centro_clicked()
{
    float x = ui->txt_centrox->text().toDouble();
    float y = ui->txt_centroy->text().toDouble();

    emit enviar_centros(QVector2D(x,y));
}

void herramientas::on_btn_reiniciar_centro_clicked()
{
    emit pedir_centro();
}

void herramientas::cambiar_spinner_max(int count)
{

    this->ui->spinner->setMaximum(count);

    if(!ui->spinner->isEnabled())
    {
        cambiar_estado_puntos(true);
        emit pedir_punto_posicion(0);

    }

}

void herramientas::cambiar_estado_puntos(bool enable)
{
    ui->spinner->setEnabled(enable);
    ui->txt_puntox->setEnabled(enable);
    ui->txt_puntoy->setEnabled(enable);
    ui->btn_guardar_punto->setEnabled(enable);
    ui->btn_eliminar_punto->setEnabled(enable);
}

void herramientas::on_spinner_valueChanged(int arg1)
{
    emit pedir_punto_posicion(arg1);

}

void herramientas::dar_puntos_texto(QVector2D punto)
{
    float x= punto.x();
    float y= punto.y();


    ui->txt_puntox->setText(QString::number(x));
    ui->txt_puntoy->setText(QString::number(y));
}



void herramientas::on_btn_guardar_punto_clicked()
{
    int index = ui->spinner->value();

    float x = ui->txt_puntox->text().toFloat();
    float y = ui->txt_puntoy->text().toFloat();

    QVector2D data = QVector2D(x,y);

    emit editar_punto(index,data);
}

void herramientas::on_rb1_clicked()
{
    emit editar_tipo(0);
}

void herramientas::on_rb2_clicked()
{
    emit editar_tipo(1);
}

void herramientas::on_btn_eliminar_punto_clicked()
{
    emit enviar_eliminar_punto(ui->spinner->value());

    emit pedir_punto_posicion(0);
    ui->spinner->setValue(0);
}
