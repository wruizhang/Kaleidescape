#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rooms.h"
#include "options.h"


namespace Ui {
class MainWindow;

}

 /*
 Welcome Page Class which hold Rooms Object and Options
  */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //Constructor
    explicit MainWindow(QWidget *parent = nullptr);

    //Destructor
    ~MainWindow();

private slots:
    /*
     Slot for when exit button is pressed
     */
    void on_exit_button_pressed();

    /*
     Slot for when start button is pressed
     */
    void on_start_button_pressed();

    /*
     Slot for when options button is pressed
     */
    void on_options_button_pressed();

    /*
     Slot for when Rooms button is pressed
     */
    void on_rooms_button_pressed();

private:
    Ui::MainWindow *ui;
    Rooms *all;
    Options *opt;

};




#endif // MAINWINDOW_H
