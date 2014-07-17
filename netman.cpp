#include "netman.h"
#include "ui_netman.h"
#define OR |

#include <stdlib.h>
#include <stdio.h>
 #include <QProcess>
#include <unistd.h>

QString conn("0% packet loss");
QString unconn("+1 errors, 100");
QString wconn("ceived, 0% pac");

Netman::Netman(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Netman)
{
    ui->setupUi(this);
}

Netman::~Netman()
{
    delete ui;
}

void Netman::on_ping_clicked()
{
   QProcess process;
   QString ip = ui->input->toPlainText();
   QString ping("ping -c 1 -q "+ip);
   process.start(ping);
   process.waitForFinished();
   QByteArray result = process.readAllStandardOutput(); //Reads standard output
   QByteArray error = process.readAllStandardError(); //Reads standard error
   QString command(result);
    command.remove(0,125);
    command.remove(14,125);
   ui->output->setText(command);
   /*if(unconn.compare(command)==0)
        ui->output->setText(" Not Connected");
    else if (wconn.compare(command)==0)
        ui->output->setText("connected");
   else if (conn.compare(command)==0)
        ui->output->setText("Connected");*/
}

void Netman::on_output_textChanged()
{

}

void Netman::on_stop_clicked()
{

}
