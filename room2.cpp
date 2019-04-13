#include "room2.h"
#include "ui_room2.h"
#include <QInputDialog>
#include <QMessageBox>


//Constructor for Room 2
room2::room2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::room2), word_counter(0),word1_correct(false), game_end(false), room2_passed(false)
{
    ui->setupUi(this);

    //consturcting room3 object and connecting it to switch with room2
    rm3 = new room3();
    rm3->setFixedSize(960,640);
    connect(rm3, &room3::ThirdRoom, this, &room2::show);
}

//defining counter to place corresponding images when user correctly guesses each word
int room2::image_counter =0;

//defining counter to count time user has failed to correctly guess word
int room2::wrong_counter =0;

//defining counter to determine which word to display
int room2::order_counter=0;

//Destructor for Room 2
room2::~room2()
{
    delete ui;
    ui=nullptr;

  if(rm3!=nullptr){
    delete rm3;
    rm3=nullptr;
  }
}



//Slot to go Back when pressed
void room2::on_backtomenu_pressed()
{
    this->hide();
    if (!word1_correct){
     this->reset_counters();
    }
    emit SecondRoom();
}



bool room2::correct_word(QString word) {
    // use private static counter to keep order of words, this is first word
    if(order_counter==0){
    //checks if word is correctly unscrambled and if so return true and add to counter to move onto next word
    if (word=="rose" || word=="ROSE"){
        order_counter++;
        word1_correct = true;
        return true;
    }
    //otherwise first word is incorrect so we return false and stick to solving first word
    else{
        return false;
    }
    }
    //moved on to second word
    if (order_counter==1){
    //checking if user input is correct and then return true
    if( word=="apple" || word == "APPLE"){
        return true;
    }
    //not correct so we return false
    else{
        return false;
    }
  }
    return false;
}


QString room2::r_or_w(bool is_it){
    //word inputted by user is correct
    if (is_it){
        //counter to keep up with each word and make changes related to it to UI
        if(image_counter==0){
        ui->rose->setIcon(QIcon(":/images/rose.png"));
        ui->rose->setIconSize(QSize(200,200));
        ui->laptop->setIcon(QIcon(":/images/applescramble.png"));
        image_counter++;
         return QString("Correct Word! Next Word");
        }
        //second word correct so make related changes to UI
       else if (image_counter==1){
            ui->apple->setIcon(QIcon(":/images/apple.png"));
            ui->apple->setIconSize(QSize(50,50));
           image_counter++;
           return QString("Congrats you Passed Room 2!");
        }
    }
    //word is incorrect
    else{
        //reached limited time of attempts so fail user
        if(wrong_counter==3){
           return QString("You Failed!");
        }
        //otherwise we just add to counter of attempts
         wrong_counter++;
        return QString("Incorrect. Please try again!");
    }
}

//slot to move to room 3 once you pass room 2
void room2::go_room3(){
    rm3->show();
    this->hide();
}



void room2::unscramble(){
 //show word scramble only when user has not passed room 2
if (game_end==false){
    bool ok;
    QString text = QInputDialog::getText(nullptr, "Unscramble Word",
                                         "Enter Word:", QLineEdit::Normal,
                                         "", &ok);
        //corectly get user inputted word check if correct and make changes
        if (ok && !text.isEmpty()) {
            QString word(text);
            bool correct=correct_word(text);
            QString output =r_or_w(correct);
            //both words are correct so move onto room3
            if (output=="Congrats you Passed Room 2!"){
               QMessageBox::information (nullptr, "Passed!", QString(output));
               game_end=true;
               room2_passed=true;
               ui->laptop->setIcon(QIcon());
               this->hide();
               ui->arrow->setIcon(QIcon(":/images/arrow.png"));
               ui->arrow->setText("Room 3");
               connect(ui->arrow, SIGNAL (pressed()),this, SLOT (go_room3()));
               this->reset_counters();
               rm3->show();

            }
            //user failed to guess word in limited # of attempts so send them back to room1
            else if(output =="You Failed!"){
                reset_counters();
                ui->rose->setIcon(QIcon());
                ui->laptop->setIcon(QIcon());
                this->close();
                emit SecondRoom();

            }
            QMessageBox::information (nullptr, "Unscramble Word", QString(output));
        }
}
}


void room2::reset_counters(){
    image_counter=0;
    order_counter=0;
    wrong_counter=0;
}


void room2::on_laptop_pressed()
{
    //show rose scramble only first time laptop is clicked
    if (word_counter==0){
    ui->laptop->setIcon(QIcon(":/images/rosescramble.png"));
    ui->laptop->setIconSize(QSize(100,100));
    word_counter++;
    }
    unscramble();
}
