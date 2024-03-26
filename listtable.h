#ifndef LISTTABLE_H
#define LISTTABLE_H

#include <QWidget>

namespace Ui {
class ListTable;
}

class ListTable : public QWidget
{
    Q_OBJECT

public:
    explicit ListTable(QWidget *parent = nullptr);
    ~ListTable();

private:
    Ui::ListTable *ui;
};

#endif // LISTTABLE_H
