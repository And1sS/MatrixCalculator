#ifndef POPUPWINDOW_H
#define POPUPWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

class PopupWindow : public QDialog
{
    Q_OBJECT
public:
    PopupWindow(QObject* parent = nullptr);

    void set_text(std::string);

private:
    QPushButton* button;
    QLabel* label;

    std::string text;
};

#endif // POPUPWINDOW_H
