#include "form.h"
#include <QLabel>
#include <QVBoxLayout>

Form::Form(QWidget *parent) : QWidget(parent) {
    QLabel *label = new QLabel("Oué");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
}
