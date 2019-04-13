#ifndef ROOM2_H
#define ROOM2_H

#include <QDialog>
#include "room3.h"



namespace Ui {
class room2;
}




//Class for Room 2 of Game
class room2 : public QDialog
{
    Q_OBJECT

public:
    //Grant friendship to Rooms to access room2's private variables
    friend class Rooms;

    //Constructor
    explicit room2(QWidget *parent = nullptr);

    //Destructor
    ~room2();

    /*
     Function that outputs different string if user is correct or wrong
     and also makes things appear in room if user is correct
     @param is_it whether user got word correct (true) or wrong (false)
     @return String depending whether they are correct or wrong
     */
    QString r_or_w(bool is_it);

    /*
     Function that checks whether user correctly unscrambles word
     @param word inputted string by user
     @return whether user got word correct or wrong
     */
    bool correct_word(QString word);


    /*
     Function Game where user has to unscramble words using other functions
     */
    void unscramble();

    /*
     Function to reset static counters to 0 when user fails
     */
    void reset_counters();


signals:
   //used to send signal when Second Room Windows is opened
   void SecondRoom();


private slots:

   /*
    Slot that appears once you pass room2 and come back and want
    to go to room3 by clicking on the arrow
    */
   void go_room3();

   /*
    Slot for when we want to go Back and then Quit
    */
   void on_backtomenu_pressed();

   /*
   Slot when user clicks on the game to unscramble appears
    */
   void on_laptop_pressed();

private:
    Ui::room2 *ui;
    room3* rm3;
    int word_counter;
    static int image_counter;
    static int wrong_counter;
    static int order_counter;
    bool word1_correct;
    bool game_end;
    bool room2_passed;

};



#endif // ROOM2_H
