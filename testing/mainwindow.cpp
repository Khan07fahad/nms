#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QPalette>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ping_clicked()
{

    QPalette* palette1 = new QPalette();
    palette1->setColor(QPalette::Button,Qt::red);

    QPalette* palette2 = new QPalette();
    palette2->setColor(QPalette::Button,Qt::green);

    QProcess process;
    QString ip =ui->input->toPlainText();
    QString ping("ping -c 1 -q "+ip);
    process.start(ping);
    process.waitForFinished();
    QString result =process.readAllStandardOutput();

    if(result.contains(" 0% packet loss",Qt::CaseInsensitive)==true)
    {
        ui->indi->setAutoFillBackground(true);
        ui->indi->setStyleSheet("background-color: green");
          ui->output->setText("Connected");
    }
    else if(result.contains("100% packet",Qt::CaseInsensitive)==true)
    {
        ui->indi->setAutoFillBackground(true);
        ui->indi->setStyleSheet("background-color: red");
             ui->output->setText("Not Connected");
    }

}

