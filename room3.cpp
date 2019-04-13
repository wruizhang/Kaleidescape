#include "room3.h"
#include "ui_room3.h"
#include <QInputDialog>
#include <QMessageBox>

//Constructor for Room 3
room3::room3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::room3), game2_end(false), room3_passed(false)
{
    ui->setupUi(this);

    //creating room4 object we want to move into
    rm4 = new room4();
    rm4->setFixedSize(960,640);
    connect(rm4, &room4::FourthRoom, this, &room3::show);
}

//defining room4 static private variables
int room3::word_count =0;
int room3::image_count =0;
int room3::wrong_count =0;
int room3::order_count=0;

//Destructor
room3::~room3()
{
    delete ui;
    ui=nullptr;

  if(rm4!=nullptr){
    delete rm4;
    rm4=nullptr;
  }
}

//Slot to go Back when Pressed
void room3::on_Back_pressed()
{
    this->close();
    emit ThirdRoom();
}

//begin unscramble game
void room3::on_book_pressed()
{
        //show only on first click
        if (word_count==0){
        ui->book->setStyleSheet({"background-image: url(:/images/boorkword.png)"});
        ui->book->setGeometry(160,100,391,221);
        ui->book->setIcon(QIcon(":/images/oceanscr.png"));
        ui->book->setIconSize(QSize(100,100));
        word_count++;
        }
        //then ask user to input word to play
        play();

    }


QString room3::right(bool answer){
    //if user is correct
    if (answer){
        //first word correct so make related changes made to UI
        if(image_count==0){
        ui->ocean->setIcon(QIcon(":/images/ocean.png"));
        ui->ocean->setIconSize(QSize(200,200));
        ui->book->setIcon(QIcon(":/images/berryscr.png"));
         image_count++;
         return QString("Correct Word! Next Word");
        }
        //move onto second word and make related changes to UI
        else if (image_count==1){
           ui->berry->setIcon(QIcon(":/images/blueberry.png"));
           ui->berry->setIconSize(QSize(200,200));
           image_count++;
           return QString("Congrats you Passed Room 3!");
        }
    }
    //user is not correct
    else{
        //user reached limited # of times to guess word so move them back to room2
        if(wrong_count==3){
           return QString("You Failed!");
        }
        else{
        //otherwise just add to # of attempts
         wrong_count++;
        return QString("Incorrect. Please try again!");
        }
    }
}


void room3::go_room4(){
    rm4->show();
    this->hide();
}

void room3::play(){
    //shown word scramble only when user has not passed room3
    if(game2_end==false){
    bool an;
    QString txt = QInputDialog::getText(nullptr, "Unscramble Word",
                                         "Enter Word:", QLineEdit::Normal,
                                         "", &an);
     //correctly get user input
    if (an && !txt.isEmpty()) {
            QString word(txt);
            bool ct=correct_word2(txt);
            QString out =right(ct);
            //user correctly guessed both words so move onto room4
            if (out=="Congrats you Passed Room 3!"){
               QMessageBox::information (nullptr, "Passed!", QString(out));
               room3_passed=true;
               this->hide();
               game2_end=true;
               ui->book->setIcon(QIcon());
               this->hide();
               ui->greenarrow->setIcon(QIcon(":/images/greenarrow.png"));
               ui->greenarrow->setText("Room 4");
              connect(ui->greenarrow, SIGNAL (pressed()),this, SLOT (go_room4()));
               rm4->show();
            }
            //user failed to guess words so kick them out of room
            else if(out =="You Failed!"){
               this->reset_count();
               ui->book->setStyleSheet("background-image: url(:/images/bookcover.png)");
               ui->book->setFlat(true);
               ui->book->setGeometry(160,100,221,51);
               ui->book->setIcon(QIcon());
               ui->ocean->setIcon(QIcon());
               emit ThirdRoom();

            }
            QMessageBox::information (nullptr, "Unscramble Word", QString(out));
        }
    }
}


bool room3::correct_word2(QString wrd) {
    //first word they must guess
    if(order_count==0){
    //checks if word is correctly unscrambled and if so return true and add to counter
    if (wrd=="ocean" || wrd=="OCEAN"){
        order_count++;
        return true;
    }
    //otherwise first word is incorrect so we return false and stick to solving first word
    else{
        return false;
    }
    }
    //moved on to second word
    if (order_count==1){
    //checking if user input is correct and then return true
    if( wrd=="blueberry" || wrd == "BLUEBERRY"){
        return true;
    }
    //not correct so we return false
    else{
        return false;
    }
  }
}




void room3::reset_count(){
    word_count=0;
    image_count=0;
    order_count=0;
    wrong_count=0;
}

