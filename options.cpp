#include "options.h"
#include "ui_options.h"


//Constructor for Options Room
Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);

   //setting audio for Game & playing it
   music = new QMediaPlayer();
   music->setMedia(QUrl("qrc:/audio/logosbg.mp3"));
   music->play();
}

//Destructor for Options also delets its objects
Options::~Options()
{
    delete ui;
    ui=nullptr;
    delete music;
    music=nullptr;
}

//Slot to go Back to Main Window and hide Options page
void Options::on_Main_Menu_pressed()
{
    this->hide();
    emit OptionsOpen();

}


//slot to turn off music
void Options::on_off_music_pressed()
{
    delete music;
    music=nullptr;
}

//slot to turn on music
void Options::on_on_music_pressed()
{
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/audio/logosbg.mp3"));
    music->play();
}
