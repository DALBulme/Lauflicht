#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"
#include <QTimer>

class gui : public QMainWindow, private Ui::gui
{
    Q_OBJECT

public:
    explicit gui(QWidget *parent = nullptr);

private slots:
    void on_startButton_clicked();
    void on_speedSlider_valueChanged(int value);

private:
    QTimer* m_timer;
    bool m_status;
    void toggle();
};

#endif // GUI_H
