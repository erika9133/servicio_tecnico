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
    void error();
    QString *m_user;
signals:
    void checkLogin();
private slots:
    void on_validar_clicked();
    void on_aceptarError_clicked();

private:
    Ui::Login *ui; 
    QString *m_pass;

};

#endif // LOGIN_H
