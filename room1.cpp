#include "room1.h"
#include "ui_room1.h"


//Constructor for Room 1
room1::room1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::room1), room1_pass(false)
{
    ui->setupUi(this);

    //creating room2 object and connecting it to switch between room1
    rm2 = new room2();
    rm2->setFixedSize(960,640);
    connect(rm2, &room2::SecondRoom, this, &room1::show);



}

//Destructor for Room1
room1::~room1()
{
    delete ui;
    ui=nullptr;

    if(rm2!=nullptr){
    delete rm2;
    rm2=nullptr;
    }

}

//Slot to go Back to Main Menu
void room1::on_BackToMenu_pressed()
{
    this->hide();
    emit FirstRoom();
}

// Slot that when Door is pressed you move on to Room 2 and unlock room 2 in Rooms
void room1::on_door_pressed()
{

        room1_pass=true;
        this->hide();
        rm2->show();


}
