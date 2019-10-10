#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    widget_herramienta=new herramientas(this->ui->centralwidget);
    widget_herramienta->setGeometry(QRect(450, 0, 150, 550));



    widget_panel=new panel(this->ui->centralwidget);
    widget_panel->setGeometry(QRect(0, 0, 450, 550));






    connect(ui->actionAbrir_Imagen,SIGNAL(triggered()),this, SLOT(on_nuevaImagen()));

    connect(this,SIGNAL(signal_imagen(QString)),widget_panel,SLOT(nueva_imagen(QString)));



}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_nuevaImagen()
{

    QString url = QFileDialog::getOpenFileName(this,tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    emit signal_imagen(url);

}
