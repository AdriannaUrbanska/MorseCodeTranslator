#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QChar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CreateTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Change_clicked()
{
    QString from = ui->Text_from->toPlainText();
    QString to = ui->Text_to->toPlainText();

    if(ui->Label_from->text() == "Coded")
    {
        ui->Label_from->setText("Decoded");
        ui->Label_to->setText("Coded");

        Code();
    }
    else
    {
        ui->Label_from->setText("Coded");
        ui->Label_to->setText("Decoded");

        Decode();
    }

//    ui->Text_from->setPlainText(to);
//    ui->Text_to->setPlainText(from);
}

void MainWindow::on_actionOpen_triggered()
{
    OpenFile();
}

void MainWindow::on_actionSave_triggered()
{
    SaveFile();
}

void MainWindow::on_actionExit_triggered()
{
    Exit();
}

void MainWindow::OpenFile()
{
    QString filter = "All files (*.*) ;; txt (*.txt)";
    QString file_name = QFileDialog::getOpenFileName(this, "..", QDir::currentPath(), filter);

    if (!file_name.isEmpty())
    {
        QFile file(file_name);
        if(!file.open(QFile::ReadOnly | QFile::Text))
            QMessageBox::warning(this, "..", "Unable to open file");
        else
        {
            QTextStream in(&file);
            QString text = in.readAll();
            ui->Text_from->setPlainText(text);
            file.close();
        }
    }
}

void MainWindow::SaveFile()
{
    QString filter = "All files (*.*) ;; txt (*.txt)";
    QString file_name = QFileDialog::getSaveFileName(this, "..", QDir::currentPath(), filter);

    if (!file_name.isEmpty())
    {
        QString ext = QFileInfo(file_name).suffix();
        if(ext == "")
            file_name += ".txt";

        QFile file(file_name);
        if (!file.open(QIODevice::WriteOnly))
            QMessageBox::warning(this, "..", "Unable to open file");
        else
        {
            QTextStream out(&file);
            out << ui->Text_to->toPlainText();
            file.close();
        }
    }
}

void MainWindow::Exit()
{
    QMessageBox::StandardButton button = QMessageBox::question(this,"Exit", "Are you sure?", QMessageBox::Yes | QMessageBox::No);

    if (button == QMessageBox::Yes)
        QApplication::quit();
}

void MainWindow::on_Open_clicked()
{
    OpenFile();
}

void MainWindow::on_Save_clicked()
{
    SaveFile();
}

void MainWindow::on_Clear_clicked()
{
    ui->Text_from->setPlainText("");
    ui->Text_to->setPlainText("");
}

void MainWindow::on_Text_from_textChanged()
{
    if(ui->Label_from->text() == "Decoded")
        Code();
    else
        Decode();
}

void MainWindow::Decode()
{
    QString text_from = ui->Text_from->toPlainText().toUpper();
    QString text_to = "";
    int len = text_from.length();
    Tree *t = &root;
    char letter_before = text_from[0].toLatin1();

    for(int i = 0; i < len; i++)
    {
        char l = text_from[i].toLatin1();

        if(l == '-')
        {
            if(t != nullptr)
                t = t->GetLeft();
        }
        else if (l == '.')
        {
            if(t != nullptr)
                t = t->GetRight();
        }
        else if(l == ' ')
        {
            if(t != nullptr)
            {
                text_to += t->GetLetter();

                if(letter_before == ' ' && !text_to.isEmpty())
                    text_to += " ";
            }
            t = &root;
        }

        letter_before = l;
    }

    ui->Text_to->setPlainText(text_to);
}

void MainWindow::Code()
{
    QString text_from = ui->Text_from->toPlainText().toUpper();
    QString text_to = "";
    int len = text_from.length();


    for(int i = 0; i < len; i++)
    {
        text_to += LetterToMorseCode(text_from[i]) + " ";
    }
    ui->Text_to->setPlainText(text_to);
}

void MainWindow::CreateTree()
{
    root.Node('T', 'E');

    root.GetLeft()->Node('M', 'N');
    root.GetRight()->Node('A', 'I');

    root.GetLeft()->GetLeft()->Node('O', 'G');
    root.GetLeft()->GetRight()->Node('K', 'D');
    root.GetRight()->GetLeft()->Node('W', 'R');
    root.GetRight()->GetRight()->Node('U', 'S');

    root.GetLeft()->GetLeft()->GetLeft()->Node('-', '.');
    root.GetLeft()->GetLeft()->GetRight()->Node('Q', 'Z');
    root.GetLeft()->GetRight()->GetLeft()->Node('Y', 'C');
    root.GetLeft()->GetRight()->GetRight()->Node('X', 'B');
    root.GetRight()->GetLeft()->GetLeft()->Node('J', 'P');
    root.GetRight()->GetLeft()->GetRight()->Node('\0', 'L');
    root.GetRight()->GetRight()->GetLeft()->Node('-', 'F');
    root.GetRight()->GetRight()->GetRight()->Node('V', 'H');

    root.GetLeft()->GetLeft()->GetLeft()->GetLeft()->Node('0', '9');
    root.GetLeft()->GetLeft()->GetLeft()->GetRight()->Node('\0', '8');
    root.GetLeft()->GetLeft()->GetRight()->GetRight()->Node('\0', '7');
    root.GetLeft()->GetRight()->GetRight()->GetRight()->Node('\0', '6');
    root.GetRight()->GetLeft()->GetLeft()->GetLeft()->Node('1', '\0');
    root.GetRight()->GetRight()->GetLeft()->GetLeft()->Node('2', '\0');
    root.GetRight()->GetRight()->GetRight()->GetLeft()->Node('2', '\0');
    root.GetRight()->GetRight()->GetRight()->GetRight()->Node('4', '5');
}

QString MainWindow::LetterToMorseCode(QCharRef letter)
{
    switch(letter.toLatin1())
    {
        case '\0':
            return "  ";
        case 'A':
            return ".-";
        case 'B':
            return "-...";
        case 'C':
            return "-.-.";
        case 'D':
            return "-..";
        case 'E':
            return ".";
        case 'F':
            return "..-.";
        case 'G':
            return "--.";
        case 'H':
            return "....";
        case 'I':
            return "..";
        case 'J':
            return ".---";
        case 'K':
            return "-.-";
        case 'L':
            return ".-..";
        case 'M':
            return "--";
        case 'N':
            return "-.";
        case 'O':
            return "---";
        case 'P':
            return ".--.";
        case 'Q':
            return "--.-";
        case 'R':
            return ".-.";
        case 'S':
            return "...";
        case 'T':
            return "-";
        case 'U':
            return "..-";
        case 'V':
            return "...-";
        case 'W':
            return ".--";
        case 'X':
            return "-..-";
        case 'Y':
            return "-.--";
        case 'Z':
            return "--..";

        default:
            return "";
    }


}
