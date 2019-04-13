#include "rooms.h"
#include "ui_rooms.h"

//Constructor for Rooms which initializes Room 1
Rooms::Rooms(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rooms)
{
    ui->setupUi(this);

    //Creates room1 object
    rm1 = new room1();
    rm1->setFixedSize(960,640);


}

//Destructor for Rooms
Rooms::~Rooms()
{
    delete ui;
    ui=nullptr;

  if(rm1!=nullptr){
    delete rm1;
    rm1=nullptr;
    }

}

//Slot to go back to Welcome page and Hide Rooms
void Rooms::on_BacktoMenu_pressed()
{
    this->hide();
    emit RoomsOpen();
}

//Slot to show Room1
void Rooms::on_room1_pressed()
{
    rm1->show();
    this->hide();
}

//Slot to show Room2
void Rooms::on_room2_pressed()

{   //show only if room 1 was passed
    if(rm1->room1_pass==true){
    rm1->rm2->show();
    this->hide();
    }
    //do nothing, lock room
    else{
        return;
    }

}

//Slot to show Room 3
void Rooms::on_room3_pressed()
{   //show only if room 1 and room 2 were passed
    if(rm1->room1_pass==true && rm1->rm2->room2_passed==true){
        rm1->rm2->rm3->show();
        this->hide();
        }
        //do nothing, lock room
        else{
            return;
        }

}

//Slot to Show room 4
void Rooms::on_room4_pressed()
{   //show only if other rooms were passed
    if(rm1->room1_pass==true && rm1->rm2->room2_passed==true && rm1->rm2->rm3->room3_passed==true){
        rm1->rm2->rm3->rm4->show();
        this->hide();
        }
        //do nothing, lock room
        else{
            return;
        }

}
