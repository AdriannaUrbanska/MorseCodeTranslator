#pragma once

#include <QMainWindow>
#include "tree.h"
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    /**
    *   Method which clears coded and decoded fields.
    */
    void on_Clear_clicked();

    /**
    *   Method which changes coded and decoded fields with each other.
    */
    void on_Change_clicked();

    /**
    *   Method which automatically decodes or encodes after typing new text.
    */
    void on_Text_from_textChanged();

    /**
    *   Method which creates the morse code tree
    */
    void CreateTree();

    /**
    *   Methods which opens the file to be encoded/decoded.
    */
    void OpenFile();

    /**
    *   Methods which saves the encoded/decoded file.
    */
    void SaveFile();

    /**
    *   Methods which exits the program.
    */
    void Exit();

    /**
    *   Methods in menuBar which opens the file to be encoded/decoded.
    */
    void on_actionOpen_triggered();

    /**
    *   Methods in menuBar which saves the encoded/decoded file.
    */
    void on_actionSave_triggered();

    /**
    *   Methods in menuBar which exits the program.
    */
    void on_actionExit_triggered();

    /**
    *   Methods which opens the file to be encoded/decoded with a pushbutton.
    */
    void on_Open_clicked();

    /**
    *   Methods which saves the encoded/decoded file with a pushbutton.
    */
    void on_Save_clicked();

    /**
    *   Methods which converts the text to Morse Code.
    */
    void Code();

    /**
    *   Methods which converts the text from Morse Code.
    */
    void Decode();

    /**
    *   Methods which returns symbol of the letter in Morse Code.
    */
    QString LetterToMorseCode(QCharRef);

private:
    Ui::MainWindow *ui;

    Tree root{'\0'};
};
