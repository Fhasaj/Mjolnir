#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Authentication;
}
QT_END_NAMESPACE

class Authentication : public QMainWindow
{
    Q_OBJECT

public:
    Authentication(QWidget *parent = nullptr);
    ~Authentication();

private:
    Ui::Authentication *ui;
};
