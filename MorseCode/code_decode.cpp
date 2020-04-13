#include "mainwindow.h"

void MainWindow::Decode()
{
    QString text_from = ui->Text_from->toPlainText().toUpper();
    QString text_to = "";
    Tree *t = &root;
    int len = text_from.length();
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
        case '0':
            return "-----";
        case '1':
            return ".----";
        case '2':
            return "..---";
        case '3':
            return "...--";
        case '4':
            return "....-";
        case '5':
            return ".....";
        case '6':
            return "-....";
        case '7':
            return "--...";
        case '8':
            return "---..";
        case '9':
            return "----.";
        default:
            return "";
    }
}
