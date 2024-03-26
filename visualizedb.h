#ifndef VISUALIZEDB_H
#define VISUALIZEDB_H

#include <QDialog>

namespace Ui {
class visualizedb;
}

class visualizedb : public QDialog
{
    Q_OBJECT

public:
    explicit visualizedb(QWidget *parent = nullptr);
    ~visualizedb();

private:
    Ui::visualizedb *ui;
};

#endif // VISUALIZEDB_H
