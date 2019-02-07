#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QString>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = 0);
    ~Login();
    QString getPassword();
    QString getUser();
signals:
    void checkLogin();
private slots:
    void on_botones_accepted();

    void on_botones_rejected();

    void on_validar_clicked();

private:
    Ui::Login *ui;
    QString *m_user;
    QString *m_pass;
};

#endif // LOGIN_H
