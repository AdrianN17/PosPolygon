#ifndef HERRAMIENTAS_H
#define HERRAMIENTAS_H

#include <QWidget>
#include <QVector2D>

namespace Ui {
class herramientas;
}

class herramientas : public QWidget
{
    Q_OBJECT

public:
    explicit herramientas(QWidget *parent = nullptr);
    ~herramientas();

private:
    Ui::herramientas *ui;

public slots:
    void editar_centros(QVector2D centro);
};

#endif // HERRAMIENTAS_H
