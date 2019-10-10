#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QVector2D>
#include <QList>

#include "herramientas.h"

namespace Ui {
class panel;
}

class panel : public QWidget
{
    Q_OBJECT

public:
    explicit panel(QWidget *parent = nullptr);
    ~panel();

    herramientas *herramienta_widget;

    QImage *img;
    bool init=false;
    QList<QVector2D> lista_click ;
    QVector2D centro;

    int index_editar=0;
    int id_editar=0;


protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *ev);

public slots:
    void nueva_imagen(QString url);
    void editar_centros(QVector2D centro);
    void entregar_centro_1();
    void entregar_punto_posicion(int index);

    void recibir_punto_editado(int index, QVector2D punto);

    void obtener_id(int id);

    void eliminar_punto(int index);

signals:
    void enviar_centros(QVector2D centro);
    void entregar_centro_2(QVector2D centro);


    void enviar_punto(QVector2D punto);
    void enviar_cantidad_lista(int count);


private:
    Ui::panel *ui;
};

#endif // PANEL_H
