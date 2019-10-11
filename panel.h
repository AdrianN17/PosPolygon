#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QVector2D>
#include <QList>
#include <QColor>

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

    QImage img;
    bool init=false;
    QList<QVector2D> lista_click ;
    QVector2D centro;

    int index_editar=0;
    int id_editar=0;

    QList<QVector2D> get_lista_click();
    QVector2D get_centro();


    QColor lista_colores[3]={Qt::red,Qt::red,Qt::red};

    bool pintar_rectas=false;

    int radio=5;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *ev);

public slots:
    void nueva_imagen(QString url);
    void nuevo_spritesheet(QString url, int x, int y, int w, int h);
    void editar_centros(QVector2D centro);
    void entregar_centro_1();
    void entregar_punto_posicion(int index);

    void recibir_punto_editado(int index, QVector2D punto);

    void obtener_id(int id);

    void eliminar_punto(int index);

    void limpiar_todo();

    void recibir_color(int combo,  QColor color);

    void recibir_radio(int radio);

    void recibir_checkbox(bool valor);

signals:
    void enviar_centros(QVector2D centro);
    void entregar_centro_2(QVector2D centro);


    void enviar_punto(QVector2D punto);
    void enviar_cantidad_lista(int count);

    void confirmar_limpieza();


private:
    Ui::panel *ui;
};

#endif // PANEL_H
