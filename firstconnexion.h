#ifndef FIRSTCONNEXION_H
#define FIRSTCONNEXION_H

#include <QWidget>

namespace Ui {
class FirstConnexion;
}

class FirstConnexion : public QWidget
{
    Q_OBJECT

public:
    explicit FirstConnexion(QWidget *parent = nullptr);
    ~FirstConnexion();

private:
    Ui::FirstConnexion *ui;
};

#endif // FIRSTCONNEXION_H
