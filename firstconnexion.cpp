#include "firstconnexion.h"
#include "ui_firstconnexion.h"

FirstConnexion::FirstConnexion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FirstConnexion)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &FirstConnexion::onPushButtonClicked);
}

FirstConnexion::~FirstConnexion()
{
    delete ui;
}

void FirstConnexion::onPushButtonClicked()
{
    // Récupérer le nom d'utilisateur et le mot de passe depuis les champs de texte
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    Droits droits("User", true, true, true);

    // Vérifier si le nom d'utilisateur ou le mot de passe est vide
    if (username.isEmpty() || password.isEmpty()) {
        // Afficher un message d'erreur si l'un des champs est vide
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    // Créer un nouvel utilisateur avec les informations saisies
    User newUser(username.toStdString(), password.toStdString(), droits); // Remplacer Droits() avec les droits appropriés
    Data::getInstance()->addUser(newUser);
}
