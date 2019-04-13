#include "room4.h"
#include "ui_room4.h"
#include <QInputDialog>
#include <QMessageBox>

//Constructor for Room 4
room4::room4(QWidget *parent):
    QDialog(parent),
    ui(new Ui::room4)
{
    ui->setupUi(this);

    //creating background for room4
    QPixmap rm4bg(":/images/room4bg.png");
    rm4bg.scaled(960,640);            
    QPalette y;
    y.setBrush(QPalette::Background,rm4bg);
    this->setPalette(y);


}


int room4::word_ct =0;
int room4::image_ct =0;
int room4::wrong_ct =0;
int room4::order_ct=0;

//Deestructor for Room 4
room4::~room4()
{
    delete ui;
    ui=nullptr;
}


//Slot to go Back to Menu when pressed
void room4::on_Back_pressed()
{
    this->hide();
    emit FourthRoom();
}

//ends game
void room4:: quit_pressed(){
    this->close();
}


void room4::on_frame_pressed()
{

        //put word on laptop if clicked on
        if (word_ct==0){
        ui->frame->setStyleSheet({"background-image: url(:/images/transparent.png)"});
        ui->frame->setStyleSheet({"background-color: transparent"});
        ui->frame->setIcon(QIcon(":/images/frogscr.png"));
        ui->frame->setIconSize(QSize(75,75));
        word_ct++;
        }
        //then ask user to input word to play
        start_game();

 }

void room4::reset_ct(){
    word_ct=0;
    image_ct=0;
    order_ct=0;
    wrong_ct=0;
}


void room4::display_end(){

    //delete room4's pushbuttons on its UI
    delete ui->frog;
    ui->frog=nullptr;

    delete ui->broccoli;
    ui->broccoli=nullptr;


    delete ui->frame;
    ui->frame=nullptr;

    delete ui->Back;
    ui->Back=nullptr;

    delete ui->label;
    ui->label=nullptr;

        //creates new background for endpage and show it
        QPixmap endpage(":/images/end.png");
        endpage.scaled(this->size());
        QPalette y;
        y.setBrush(QPalette::Background,endpage);
        this->setPalette(y);

        QLabel *congrats = new QLabel(this);
        congrats->setText("Congratulations! ");
        QFont ft("Impact", 25, QFont::Bold);
        congrats->setFont(ft);
        congrats->move(350,250);
        const QSize end_sz = QSize(200, 200);
        congrats->setMinimumSize(end_sz);
        congrats->show();

        QPushButton* quit = new QPushButton(this);
        quit->setGeometry(860,590,75,41);
        quit->setText("Quit");
        QFont font("Impact", 12, QFont::Bold);
        quit->setFont(font);
        connect(quit, SIGNAL(pressed()), this, SLOT (quit_pressed()));
        quit->show();



}


void room4::start_game(){

    bool st;
    QString tx = QInputDialog::getText(nullptr, "Unscramble Word",
                                         "Enter Word:", QLineEdit::Normal,
                                         "", &st);
       //correctly get user input
    if (st && !tx.isEmpty()) {
            QString word(tx);
            bool ct=check(tx);
            QString out =set(ct);
            //user correctly guessed both words so move onto room3
            if (out=="Congrats you Passed Room 4!"){
               QMessageBox::information (nullptr, "Passed!", QString(out));
               this->display_end();

            }
            //user fails to correct word so move them back to room3
             else if (out=="You Failed!"){
                this->reset_ct();
                ui->frame->setStyleSheet("background-image: url(:/images/frame.png);");
                ui->frame->setIcon(QIcon());
                ui->frog->setIcon(QIcon());
                emit FourthRoom();

             }

            QMessageBox::information (nullptr, "Unscramble Word", QString(out));
        }

}



QString room4::set(bool ans){
    //if user is correct
    if (ans){
        //first word
        if(image_ct==0){
        ui->frog->setIcon(QIcon(":/images/frog.png"));
        ui->frog->setIconSize(QSize(75,75));
        ui->frame->setIcon(QIcon(":/images/brocolliscr.png"));
        image_ct++;
         return QString("Correct Word! Next Word");
        }
        //move onto second word
       else if (image_ct==1){
           ui->broccoli->setIcon(QIcon(":/images/broccoli.png"));
           ui->broccoli->setIconSize(QSize(300,300));
           image_ct++;
           return QString("Congrats you Passed Room 4!");
        }
    }
    //user is not correct
    else{
        //counter to keep up with how many times user guesses wrong
        //if gets wrong over 3 times
        if(wrong_ct==3){
           return QString("You Failed!");
        }
         wrong_ct++;
        return QString("Incorrect. Please try again!");
    }
}


bool room4::check(QString in) {
    //first word they must guess
    if(order_ct==0){
    //checks if word is correctly unscrambled and if so return true and add to counter
    if (in=="frog" || in=="FROG"){
        order_ct++;
        return true;
    }
    //otherwise first word is incorrect so we return false and stick to solving first word
    else{
        return false;
    }
    }
    //moved on to second word
    if (order_ct==1){
    //checking if user input is correct and then return true
    if( in=="broccoli" || in == "BROCCOLI"){
        return true;
    }
    //not correct so we return false
    else{
        return false;
    }
  }
}



