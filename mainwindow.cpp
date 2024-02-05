#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QStackedWidget>
#include <QUiLoader>
#include <QFile>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
        initUI();
    }

private slots:
    void loginClicked() {
        // Lorsque le bouton de connexion est cliqué, basculer vers la page de confirmation
        stackedWidget->setCurrentIndex(1);
    }

private:
    void initUI() {
        setWindowTitle("Application de Connexion");
        setGeometry(300, 300, 400, 200);

        // Charger le fichier UI pour la page de connexion
        QUiLoader loader;
        QFile fileConnexion("mainwindow.ui");
        fileConnexion.open(QFile::ReadOnly);
        pageConnexion = loader.load(&fileConnexion, this);
        fileConnexion.close();

        // Charger le fichier UI pour la page de confirmation
        QFile fileConfirmation("form.ui");
        fileConfirmation.open(QFile::ReadOnly);
        pageConfirmation = loader.load(&fileConfirmation, this);
        fileConfirmation.close();

        // Créer un QStackedWidget pour gérer les pages
        stackedWidget = new QStackedWidget(this);

        // Ajouter les pages au QStackedWidget
        stackedWidget->addWidget(pageConnexion);
        stackedWidget->addWidget(pageConfirmation);

        // Connexion du bouton "Se Connecter"
        QPushButton *btnLogin = pageConnexion->findChild<QPushButton*>("btnLogin");
        connect(btnLogin, &QPushButton::clicked, this, &MainWindow::loginClicked);

        // Créer un layout principal
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(stackedWidget);
    }

    QStackedWidget *stackedWidget;
    QWidget *pageConnexion;
    QWidget *pageConfirmation;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}

#include "main.moc"
