#include "panel.h"
#include "ui_panel.h"

panel::panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::panel)
{
    ui->setupUi(this);

    centro.setX(0);
    centro.setY(0);

}

panel::~panel()
{
    delete ui;
}

void panel::nueva_imagen(QString url)
{

     img.load(url);

     centro.setX(img.width()/2);
     centro.setY(img.height()/2);

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

        painter.drawImage(0, 0, img);

        painter.setPen(lista_colores[0]);

        painter.drawText(centro.x(),centro.y()-10, "Centro");
        painter.drawEllipse(centro.x(),centro.y(),radio,radio);

        if(pintar_rectas)
        {
            for(auto i=0; i<lista_click.count()-1;i++)
            {
                auto vec1 = lista_click[i];
                auto vec2 = lista_click[i+1];




                painter.setPen(lista_colores[2]);
                painter.drawLine(vec1.x(),vec1.y(),vec2.x(),vec2.y());

            }

            auto veci = lista_click[0];
            auto vecf = lista_click.last();

            painter.drawLine(vecf.x(),vecf.y(),veci.x(),veci.y());
        }

        int i=0;
        foreach (auto vector, lista_click) {

            painter.setPen(lista_colores[1]);

            painter.drawText(vector.x(),vector.y()-10, QString::number(i));
            painter.drawEllipse(vector.x(),vector.y(),radio,radio);
            i++;
        }




    }



    update();

}

void panel::mousePressEvent(QMouseEvent *ev)
{
    if(init)
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
}

void panel::entregar_centro_1()
{
    if(init)
    {

        centro.setX(img.width()/2);
        centro.setY(img.height()/2);

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

void panel::nuevo_spritesheet(QString url, int x, int y, int w, int h)
{
    img.load(url);

    QRect rect(x, y, w, h);
    auto sprite = img.copy(rect);

    img = sprite;

    centro.setX(img.width()/2);
    centro.setY(img.height()/2);

    emit enviar_centros(centro);

    init=true;
}

QList<QVector2D> panel::get_lista_click()
{
    return this->lista_click;
}

QVector2D panel::get_centro()
{
    return this->centro;
}

void panel::limpiar_todo()
{
    this->lista_click.clear();
    this->centro = QVector2D(0,0);

    img = QImage();

    emit confirmar_limpieza();

}

void panel::recibir_color(int combo, QColor color)
{
    qDebug()<<color;
    lista_colores[combo]=color;
}

void panel::recibir_radio(int radio)
{
    this->radio=radio;
}

void panel::recibir_checkbox(bool valor)
{
    this->pintar_rectas=valor;
}
