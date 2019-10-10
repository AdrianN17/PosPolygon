#include "herramientas.h"
#include "ui_herramientas.h"

herramientas::herramientas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::herramientas)
{
    const int max=450;

    ui->setupUi(this);

    ui->txt_centrox->setValidator( new QDoubleValidator(0, max, 2, this) );
    ui->txt_centrox->setValidator( new QDoubleValidator(0, max, 2, this) );


}

herramientas::~herramientas()
{
    delete ui;
}

void herramientas::editar_centros(QVector2D centro)
{
    float x= centro.x();
    float y= centro.y();


    ui->txt_centrox->setText(QString::number(x, 'f', 2));
    ui->txt_centroy->setText(QString::number(y,'f', 2));
}
