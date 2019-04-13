#ifndef ROOM4_H
#define ROOM4_H

#include <QDialog>




namespace Ui {
class room4;
}


//Class for Room 4
class room4 : public QDialog
{
    Q_OBJECT

public:
    //Constructor for Room 4
    explicit room4(QWidget *parent = nullptr);

    //Destructor for Room 4
    ~room4();


    /*
     Function that checks whether user correctly unscrambles word
     @param in inputted string by user
     @return whether user got word correct or wrong
     */
    bool check(QString in);

    /*
     Function Game where user has to unscramble words using other functions
     */
    void start_game();


    /*
     Function that outputs different string if user is correct or wrong
     and also makes things appear in room if user is correct
     @param ans whether user got word correct (true) or wrong (false)
     @return String depending whether they are correct or wrong
     */
    QString set(bool ans);

      /*
       Function to display endpage when game is passed
      */
      void display_end();

      /*
      Function to reset static counters when user failed
      */
      void reset_ct();


signals:
   //used to send signal when Fourth Room Windows is opened
   void FourthRoom();



private slots:
   /*
    * Slot to go back to Menu from this room
   */
   void on_Back_pressed();

   /*
    * Slot to go start game when frame is pressed
   */
   void on_frame_pressed();

   /*
    * Slot to Quit game when passed
   */
   void quit_pressed();

private:
    Ui::room4 *ui;
    static int word_ct;
    static int image_ct;
    static int wrong_ct;
    static int order_ct;
};

#endif // ROOM4_H
