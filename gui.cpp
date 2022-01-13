#include "gui.h"
#include <QDebug>

gui::gui(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    m_timer = new QTimer();
}

void gui::on_startButton_clicked()
{
    m_timer->start(1000);
    // Verbinde Quelle (Timeout aus Klasse Timer) -> Ziel (Toggle Funktion aus Klasse Gui)
    connect(m_timer, &QTimer::timeout,this, &gui::toggle);
}

void gui::toggle()
{
    qDebug() << "Jesus";
}
