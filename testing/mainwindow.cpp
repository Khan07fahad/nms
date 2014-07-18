#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QPalette>
#include <QFile>
#include <QDataStream>




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
    QProcess process;
    QString ip =ui->input->toPlainText();
    QString ping("ping -c 1 -q "+ip);
    process.start(ping);
    process.waitForFinished();
    QString result =process.readAllStandardOutput();

    if(result.contains(" 0% packet loss",Qt::CaseInsensitive)==true)
    {
        /*QString a=result.remove(0,106);
        QString b=a.remove(2,152);
        QString myString = b;
        int number = myString.mid(1,1).toInt();
        ui->bandw->setValue(number);*/
        ui->indi->setAutoFillBackground(true);
        ui->indi->setStyleSheet("background: qlineargradient( x1:0 y1:0, x2:0 y2:1, stop:0 #007300, stop:1 #7fbf7f)");
        ui->output->setText("Connected");
    }
    else if(result.contains("100% packet",Qt::CaseInsensitive)==true)
    {
        ui->indi->setAutoFillBackground(true);
        ui->indi->setStyleSheet("background: qlineargradient( x1:0 y1:0, x2:0 y2:1, stop:0 #e50000, stop:1 #ff7f7f)");
        ui->output->setText("Not Connected");
        /*ui->bandw->setValue(0);*/
    }

}


void MainWindow::on_ping_2_clicked()
{
    QProcess ps,ps1;
    QString r1=ui->ip1->toPlainText();
                         QString p1=ui->ip2->toPlainText();
                         QRegExp rx("(\\.)");
                         QStringList qy = p1.split(rx);
    QString r2=qy.at(3).toLocal8Bit().constData();
    QString nmap("nmap -sP "+r1+"-" +r2+"|grep -o '[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}'");
    ui->ot2->setText(nmap);
    ps.start(nmap);
    ps.waitForFinished();
    QString result2=ps.readAllStandardOutput();
   // result2.split()
 /*   QFile file("input.txt");
    file.open(QIODevice::ReadWrite);
    QDataStream out(&file);
    out << QString(result2);*/

   /* QString qs("grep '[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}' input.txt");
    ps1.start(qs);
    ps1.waitForFinished();
    QString res=ps1.readAllStandardOutput();
    ui->ot->setText(res);
   // ui->ot2->setText("unsucess");
*/

ui->ot->setText(result2);


}
