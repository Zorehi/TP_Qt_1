#ifndef PROFILPAGE_H
#define PROFILPAGE_H

#include <QWidget>
#include <QString>

namespace Ui {
class ProfilPage;
}

class ProfilPage : public QWidget
{
    Q_OBJECT

public:
    explicit ProfilPage(const QString& profileName, QWidget *parent = nullptr);
    ~ProfilPage();

private:
    Ui::ProfilPage *ui;
};

#endif // PROFILPAGE_H
