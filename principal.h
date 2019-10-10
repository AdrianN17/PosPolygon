#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include<QDebug>
#include<QFileDialog>
#include "panel.h"
#include "herramientas.h"
#include <QVector2D>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
protected:
    QWidget *widget_panel;

protected slots:
    void on_nuevaImagen();
    void on_importar();
    void on_nuevoSpritesheet();
signals:
    void signal_imagen(QString url);

private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
