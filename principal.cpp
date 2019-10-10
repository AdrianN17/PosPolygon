#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    auto panel_w=new panel(this->ui->centralwidget);
    widget_panel=panel_w;
    widget_panel->setGeometry(QRect(0, 0, 450, 550));

    auto herramienta_w=new herramientas();

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(herramienta_w,"Herramientas");

    //menubar
    connect(ui->actionAbrir_Imagen,SIGNAL(triggered()),this, SLOT(on_nuevaImagen()));
    connect(ui->actionAbrir_Spritesheet,SIGNAL(triggered()),this,SLOT(on_nuevoSpritesheet()));
    connect(ui->actionImportar,SIGNAL(triggered()),this, SLOT(on_importar()));

    //imagen

    connect(this,SIGNAL(signal_imagen(QString)),widget_panel,SLOT(nueva_imagen(QString)));


    //centro
    connect(panel_w,SIGNAL(enviar_centros(QVector2D)),herramienta_w,SLOT(editar_centros(QVector2D)));
    connect(herramienta_w,SIGNAL(enviar_centros(QVector2D)),panel_w,SLOT(editar_centros(QVector2D)));

    //enviar centro
    connect(herramienta_w,SIGNAL(pedir_centro()),panel_w,(SLOT(entregar_centro_1())));
    connect(panel_w,SIGNAL(entregar_centro_2(QVector2D)),herramienta_w,SLOT(editar_centros(QVector2D)));

    //spinner
    connect(panel_w,SIGNAL(enviar_cantidad_lista(int)),herramienta_w,SLOT(cambiar_spinner_max(int)));

    connect(herramienta_w,SIGNAL(pedir_punto_posicion(int)), panel_w,SLOT(entregar_punto_posicion(int)));
    connect(panel_w,SIGNAL(enviar_punto(QVector2D)), herramienta_w, SLOT(dar_puntos_texto(QVector2D)));

    connect(herramienta_w,SIGNAL(editar_punto(int, QVector2D)), panel_w,SLOT(recibir_punto_editado(int, QVector2D)));

    //radiobutton
    connect(herramienta_w,SIGNAL(editar_tipo(int)),panel_w,SLOT(obtener_id(int)));

    //eliminar

    connect(herramienta_w, SIGNAL(enviar_eliminar_punto(int)), panel_w, SLOT(eliminar_punto(int)));

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

void Principal::on_importar()
{

}

void Principal::on_nuevoSpritesheet()
{
    QString url = QFileDialog::getOpenFileName(this,tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    /*
     *  QRect rect(10, 20, 30, 40);
QImage original('image.png');
QImage cropped = original.copy(rect);
     * */

}
