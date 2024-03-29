#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QLineEdit>

class LoginPage : public QWidget {
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);

signals:
    void connexionClicked(const QString& login, const QString& password);

private slots:
    void onConnexionClicked();

private:
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditPassword;
};

#endif // LOGINPAGE_H
