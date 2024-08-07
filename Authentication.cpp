#include "Authentication.h"
#include "./ui_Authentication.h"

Authentication::Authentication(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Authentication)
{
    ui->setupUi(this);
}

Authentication::~Authentication()
{
    delete ui;
}
