#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    panel_w=new panel(this->ui->centralwidget);

    QWidget *widget_panel=panel_w;
    widget_panel->setGeometry(QRect(0, 0, 450, 550));

    auto herramienta_w=new herramientas();
    auto extra_w=new extra();

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(herramienta_w,"Herramientas");
    ui->tabWidget->addTab(extra_w,"Extra");

    //menubar
    connect(ui->actionAbrir_Imagen,SIGNAL(triggered()),this, SLOT(on_nuevaImagen()));
    connect(ui->actionAbrir_Spritesheet,SIGNAL(triggered()),this,SLOT(on_nuevoSpritesheet()));
    connect(ui->actionImportar,SIGNAL(triggered()),this, SLOT(on_importar()));

    //imagen

    connect(this,SIGNAL(signal_imagen(QString)),widget_panel,SLOT(nueva_imagen(QString)));
    connect(this,SIGNAL(signal_spritesheet(QString, int, int, int ,int)), widget_panel, SLOT(nuevo_spritesheet(QString, int, int, int ,int)));


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

    connect(herramienta_w, SIGNAL(enviar_limpieza()), panel_w , SLOT(limpiar_todo()));

    connect(panel_w,SIGNAL(confirmar_limpieza()), herramienta_w, SLOT(limpieza_campos()));

    // colores

    connect(extra_w, SIGNAL(enviar_color(int,QColor)), panel_w,SLOT(recibir_color(int,QColor)));

    //radio
    connect(extra_w,SIGNAL(enviar_radio(int)), panel_w, SLOT(recibir_radio(int)));

    //lineas

    connect(extra_w,SIGNAL(enviar_checkbox(bool)), panel_w, SLOT(recibir_checkbox(bool)));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_nuevaImagen()
{

    QString url = QFileDialog::getOpenFileName(this,tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    if(!url.isEmpty())
    {
        emit signal_imagen(url);
    }

}

void Principal::on_importar()
{
    QString url = QFileDialog::getSaveFileName(this, tr("Save File"), tr("Images (*.txt)"));

    QFile file( url );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << "{" << endl;
        auto lista_click = panel_w->get_lista_click();
        auto centro = panel_w->get_centro();
        foreach (auto vector,  lista_click) {
            stream << vector.x()-centro.x() << " , "  << vector.y()-centro.y()<<","<<endl;
        }
        stream << "}" << endl;
    }
}

void Principal::on_nuevoSpritesheet()
{
    QString url = QFileDialog::getOpenFileName(this,tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    if(!url.isEmpty())
    {
        d_dato = new datos();

        int x,y,w,h;

        if(d_dato->exec() == QDialog::Accepted)
        {
            x= d_dato->get_x();
            y= d_dato->get_y();
            w= d_dato->get_w();
            h= d_dato->get_h();

            if(w<=0 && h<=0)
            {
                QMessageBox msgBox;
                msgBox.setText("Dimensiones deben ser mayor a 0");
                msgBox.exec();
            }
            else
            {
                emit signal_spritesheet(url,x,y,w,h);
            }
        }
    }

}
