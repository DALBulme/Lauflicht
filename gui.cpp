#include "gui.h"
#include <QDebug>

gui::gui(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    m_timer = new QTimer();
    m_status = false;
    // Verbinde Quelle (Timeout aus Klasse Timer) -> Ziel (Toggle Funktion aus Klasse Gui)
    connect(m_timer, &QTimer::timeout,this, &gui::toggle);
}

void gui::on_startButton_clicked()
{
    m_timer->start(1000/speedSlider->value());
}

void gui::toggle()
{
    qDebug() << "toggle";
    m_status = !m_status;
    blinkLabel->setNum(m_status);
}

void gui::on_speedSlider_valueChanged(int value)
{
    if (m_timer->isActive())
    m_timer->start(1000/value); //slider 1-10 -> 1000-100 ms
}
