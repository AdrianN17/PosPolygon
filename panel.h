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


protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *ev);

public slots:
    void nueva_imagen(QString url);
signals:
    void enviar_centro(QVector2D centro);

private:
    Ui::panel *ui;
};

#endif // PANEL_H
