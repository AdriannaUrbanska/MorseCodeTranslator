#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "tree.h"

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
    void on_Change_clicked();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionExit_triggered();
    void OpenFile();
    void SaveFile();
    void Exit();

    void on_Open_clicked();

    void on_Clear_clicked();

    void on_Text_from_textChanged();

    void on_Save_clicked();

    void Encode();

    void Decode();

    void CreateTree();

    QString LetterToMorseCode(QCharRef);

private:
    Ui::MainWindow *ui;

    Tree root{'\0'};

};

#endif // MAINWINDOW_H
