#include "scenario.h"

// Constructor
Scenario::Scenario(QWidget *parent) : QWidget(parent)
{
    QPushButton *button = new QPushButton("Hello world!", this);

    button->setGeometry(10, 10, 80, 30);
    this->show();
}
