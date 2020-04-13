#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Morse Code Translator");
    CreateTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Clear_clicked()
{
    ui->Text_from->setPlainText("");
    ui->Text_to->setPlainText("");
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
}

void MainWindow::on_Text_from_textChanged()
{
    if(ui->Label_from->text() == "Decoded")
        Code();
    else
        Decode();
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
