#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include<QDebug>
#include<QFileDialog>
#include <QVector2D>
#include <QMessageBox>

#include "panel.h"
#include "herramientas.h"
#include "datos.h"
#include "extra.h"

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
    datos *d_dato;
    panel *panel_w;

protected slots:
    void on_nuevaImagen();
    void on_importar();
    void on_nuevoSpritesheet();
signals:
    void signal_imagen(QString url);
    void signal_spritesheet(QString url,int x, int y, int w, int h);

private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
