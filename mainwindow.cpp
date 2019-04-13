#include "mainwindow.h"
#include "ui_mainwindow.h"


//Constructor for Welcome Page (Main Menu)
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set Windows size
    this->setFixedSize(960,640);

    /*
    creating Rooms Menu and connecting it to MainWindow so they
    can switch between being shown
    */
    all = new Rooms();
    all->setFixedSize(960,640);
    connect(all, &Rooms::RoomsOpen, this, &MainWindow::show);

    /*
    creating Options Menu and connecting it to MainWindow so they
    can switch between being shown
    */
    opt = new Options();
    opt->setFixedSize(960,640);
    connect(opt, &Options::OptionsOpen, this, &MainWindow::show);

    //connect room1 object to go back to MainWindow
     connect(all->rm1,&room1::FirstRoom, this, &MainWindow::show);


}

//closes whole program
void MainWindow::on_exit_button_pressed()
{
   this->close();

}

//MainWindow Desturctor that deletes all of it's objects and itself
MainWindow::~MainWindow()
{
    delete ui;
    ui=nullptr;

    delete opt;
    opt=nullptr;

    delete all;
    all=nullptr;
}


//Slot for Room 1 to show when Start Button is pushed and closes MainWindow
void MainWindow::on_start_button_pressed()
{
    all->rm1->show();
    this->hide();
}

//Slot for Options Room to show and MainWindow hide
void MainWindow::on_options_button_pressed()
{
    opt->show();
    this->hide();

}

//Slot for Rooms to show and MainWindow hides
void MainWindow::on_rooms_button_pressed()
{
    all->show();
    this->hide();
}
