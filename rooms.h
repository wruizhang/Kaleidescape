#ifndef ROOMS_H
#define ROOMS_H

#include <QDialog>

#include "room1.h"



namespace Ui {
class Rooms;
}

//Class which holds a room1 object
class Rooms : public QDialog
{
    Q_OBJECT

public:
    //make MainWindow a friend to give it access to the rooms
    friend class MainWindow;


    //Constructor for Rooms
    explicit Rooms(QWidget *parent = nullptr);

    //Destructor for Rooms
    ~Rooms();

signals:
   //used to send signal when Rooms Menu Window is opened
   void RoomsOpen();

private slots:
   /*
    Slot to go Back to Main Menu button is pressed
    */
   void on_BacktoMenu_pressed();

   /*
    Slot to go to Room 1
    */
   void on_room1_pressed();

   /*
    Slot to go to Room 2, it is "locked" until the user passes room1
    */
   void on_room2_pressed();

   /*
    Slot to go to Room 3, it is "locked" until the user passes room2 and room 1
    */
   void on_room3_pressed();

   /*
    Slot to go to Room 4, it is "locked" until the user passes other rooms
    */
   void on_room4_pressed();

private:
    Ui::Rooms *ui;
    room1 *rm1;



};

#endif // ROOMS_H
