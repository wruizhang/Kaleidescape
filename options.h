#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include <QMediaPlayer>

namespace Ui {
class Options;
}

/*
 Options Window which user can change audio from ON/OFF
 */
class Options : public QDialog
{
    Q_OBJECT

public:
    //Constructor
    explicit Options(QWidget *parent = nullptr);

    //Destructor
    ~Options();

signals:
    //used to send signal when Option Windows is opened
    void OptionsOpen();

private slots:

    /*
     Slot for when Back to Menu button is pressed
     */
    void on_Main_Menu_pressed();

    /*
     Slot to turn off music
     */
    void on_off_music_pressed();

    /*
     Slot to turn on music
     */
    void on_on_music_pressed();

private:
    Ui::Options *ui;
    QMediaPlayer* music;
};

#endif // OPTIONS_H
