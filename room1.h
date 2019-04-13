#ifndef ROOM1_H
#define ROOM1_H

#include <QDialog>
#include "room2.h"



namespace Ui {
class room1;
}


//Class for Room 1 of Game
class room1 : public QDialog
{
    Q_OBJECT

public:
    //Grant friendship to Rooms to access room1's private variables
    friend class Rooms;

    //Constructor for Room 1
    room1(QWidget *parent = nullptr);

    //Destructor
    ~room1();

 signals:
    //used to send signal when First Room Windows is opened
    void FirstRoom();


private slots:
    /*
     Slot to Back to Menu and Quit button is pressed
     */
    void on_BackToMenu_pressed();

public slots:
    /*
    Slot for when door is pressed in room 1
     */
    void on_door_pressed();



private:
    Ui::room1 *ui;
    room2* rm2;
    bool room1_pass;


};

#endif // ROOM1_H
