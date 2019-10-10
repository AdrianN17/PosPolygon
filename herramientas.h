#ifndef HERRAMIENTAS_H
#define HERRAMIENTAS_H

#include <QWidget>
#include <QVector2D>
#include <qdebug.h>

namespace Ui {
class herramientas;
}

class herramientas : public QWidget
{
    Q_OBJECT

public:
    explicit herramientas(QWidget *parent = nullptr);
    ~herramientas();

    void cambiar_estado_puntos(bool enable);


private:
    Ui::herramientas *ui;

public slots:
    void editar_centros(QVector2D centro);
    void dar_puntos_texto(QVector2D punto);
signals:
    void enviar_centros(QVector2D centro);
    void pedir_centro();
    void pedir_punto_posicion(int index);
    void editar_punto(int index, QVector2D punto);
    void editar_tipo(int id);

    void enviar_eliminar_punto(int index);

private slots:
    void on_btn_guardar_centro_clicked();
    void on_btn_reiniciar_centro_clicked();
    void cambiar_spinner_max(int count);
    void on_spinner_valueChanged(int arg1);
    void on_btn_guardar_punto_clicked();
    void on_rb1_clicked();
    void on_rb2_clicked();
    void on_btn_eliminar_punto_clicked();
};

#endif // HERRAMIENTAS_H
