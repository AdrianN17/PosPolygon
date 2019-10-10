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




    //connect(this,SIGNAL(enviar_centro(Vector2D)),parent,)
}

panel::~panel()
{
    delete ui;
}

void panel::nueva_imagen(QString url)
{

     qDebug() <<url;
     img->load(url);

     centro.setX(img->width()/2);
     centro.setY(img->height()/2);



     init=true;

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

    lista_click.append(QVector2D(ev->x(),ev->y()));

}
