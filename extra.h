#ifndef EXTRA_H
#define EXTRA_H

#include <QWidget>
#include <QComboBox>
#include <QtDebug>

namespace Ui {
class extra;
}

class extra : public QWidget
{
    Q_OBJECT

public:
    explicit extra(QWidget *parent = nullptr);
    ~extra();

    QColor get_color(int index);

private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_combo1_currentIndexChanged(int index);

    void on_combo2_currentIndexChanged(int index);

    void on_combo3_currentIndexChanged(int index);

    void insertar_colores(QComboBox *combo);

    void on_spinner_tamano_valueChanged(int arg1);

signals:
    void enviar_color(int combo, QColor color);
    void enviar_checkbox(bool valor);
    void enviar_radio(int radio);

private:
    Ui::extra *ui;
};

#endif // EXTRA_H
