#include "panel.h"
#include "ui_panel.h"

panel::panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::panel)
{
    ui->setupUi(this);
    img = new QImage;

    centro.setX(0);
    centro.setY(0);

}

panel::~panel()
{
    delete ui;
}

void panel::nueva_imagen(QString url)
{

     img->load(url);

     centro.setX(img->width()/2);
     centro.setY(img->height()/2);

    emit enviar_centros(centro);

     init=true;

}

void panel::editar_centros(QVector2D centro)
{
    this->centro=centro;
}

void panel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if(init)
    {
        painter.drawImage(0, 0, *img);
    }

    painter.drawText(centro.x(),centro.y()-10, "Centro");
    painter.drawEllipse(centro.x(),centro.y(),5,5);


    int i=0;
    foreach (auto vector, lista_click) {
        painter.drawText(vector.x(),vector.y()-10, QString::number(i));
        painter.drawEllipse(vector.x(),vector.y(),5,5);
        i++;
    }

    update();

}

void panel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons() == Qt::LeftButton)
    {

        lista_click.append(QVector2D(ev->x(),ev->y()));

        emit enviar_cantidad_lista(lista_click.count()-1);

    }
    else if(ev->buttons() == Qt::RightButton)
    {

        if(id_editar==0)
        {
            auto punto = QVector2D(ev->x(),ev->y());
            centro=punto;
            emit entregar_centro_2(this->centro);
        }
        else if(id_editar==1 && !lista_click.isEmpty())
        {
            auto punto = QVector2D(ev->x(),ev->y());
            lista_click[index_editar] = punto;
            emit enviar_punto(punto);
        }

    }
}

void panel::entregar_centro_1()
{
    if(init)
    {

        centro.setX(img->width()/2);
        centro.setY(img->height()/2);

    }
    else
    {
        centro.setX(0);
        centro.setY(0);
    }


    emit entregar_centro_2(this->centro);
}

void panel::entregar_punto_posicion(int index)
{
    auto punto = lista_click[index];
    index_editar=index;

    emit enviar_punto(punto);

}

void panel::recibir_punto_editado(int index, QVector2D punto)
{
    lista_click[index] = punto;
}

void panel::obtener_id(int id)
{
    id_editar=id;
}

void panel::eliminar_punto(int index)
{
    lista_click.removeAt(index);
    emit enviar_cantidad_lista(lista_click.count()-1);
}
