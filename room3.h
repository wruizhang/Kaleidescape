#ifndef ROOM3_H
#define ROOM3_H

#include <QDialog>
#include "room4.h"



namespace Ui {
class room3;
}


//Class for Room 3 of Game
class room3 : public QDialog
{
    Q_OBJECT

public:
    //Grant friendship to Rooms to access room3's private variables
    friend class Rooms;

    //Constructor for Room 3
    explicit room3(QWidget *parent = nullptr);

    //Destructor for Room 3
    ~room3();

    /*
     Function to reset static counters to 0 when user fails
     */
    void reset_count();

    /*
     Function that checks whether user correctly unscrambles word
     @param wrd inputted string by user
     @return whether user got word correct or wrong
     */
     bool correct_word2(QString wrd);

     /*
      Function Game where user has to unscramble words using other functions
      */
     void play();

     /*
      Function that outputs different string if user is correct or wrong
      and also makes things appear in room if user is correct
      @param answer whether user got word correct (true) or wrong (false)
      @return string depending whether they are correct or wrong
      */
     QString right(bool answer);


signals:
   //used to send signal when Second Room Windows is opened
   void ThirdRoom();


private slots:
   /*
    Slot that appears once you pass room3 and come back and want
    to go to room4 by clicking on the arrow
    */
   void go_room4();

   /*
   Slot for when Back to Menu is pressed
    */
   void on_Back_pressed();

   /*Slot to begin Room 3 unscramble game
    */
   void on_book_pressed();

private:
    Ui::room3 *ui;
    room4* rm4;
    static int word_count;
    static int image_count;
    static int wrong_count;
    static int order_count;
    bool game2_end;
    bool room3_passed;
};






#endif // ROOM3_H
