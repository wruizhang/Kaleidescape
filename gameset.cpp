//#include "gameset.h"
//#include "ui_gameset.h"
#include "mainwindow.h"

GameSet::GameSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameSet)
{
    ui->setupUi(this);
}

GameSet::~GameSet()
{
    delete ui;
}


