#include "popupwindow.h"

PopupWindow::PopupWindow(QObject* parent) : QDialog ()
{
    setFixedSize(200, 150);
    setWindowFlags(Qt::Window
        | Qt::WindowMinimizeButtonHint
        | Qt::WindowMaximizeButtonHint);

    QGridLayout* layout = new QGridLayout();

    button = new QPushButton();
    button->setText("Ok");
    button->setFixedSize(150, 50);

    label = new QLabel();
    label->setFixedSize(150, 50);
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label, 0, 0);
    layout->addWidget(button, 1, 0);
    layout->setAlignment(Qt::AlignCenter);

    setLayout(layout);
    QObject::connect(button, SIGNAL(pressed()), parent, SLOT(enable()));
}

void PopupWindow::set_text(std::string text)
{
    label->setText(QString::fromUtf8(text.c_str()));
}
