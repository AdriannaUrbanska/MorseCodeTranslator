#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

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
    QMessageBox::StandardButton button =
            QMessageBox::question(this,"Exit", "Are you sure?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (button == QMessageBox::Yes)
        QApplication::quit();
}

void MainWindow::on_actionOpen_triggered() { OpenFile(); }

void MainWindow::on_actionSave_triggered() { SaveFile(); }

void MainWindow::on_actionExit_triggered() { Exit(); }

void MainWindow::on_Open_clicked() { OpenFile(); }

void MainWindow::on_Save_clicked() { SaveFile(); }
