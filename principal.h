#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include<QDebug>
#include<QFileDialog>
#include "panel.h"
#include "herramientas.h"

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
    QWidget *widget_herramienta;

protected slots:
    void on_nuevaImagen();
signals:
    void signal_imagen(QString url);

private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
