#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   qint32 k=1;
    ui->setupUi(this);
    ui->gridLayoutSummary->setHorizontalSpacing(0);
    ui->gridLayoutSummary->setSpacing(0);
    ui->gridLayoutSummary->setVerticalSpacing(0);
    for(int i=0; i<16; i++) {
        for(int j=0; j<16; j++) {

            machine[i][j] = new QPushButton(QString::number(k++));
            ui->gridLayoutSummary->addWidget(machine[i][j], i, j);
        }
    }
    machine[5][5]->setAutoFillBackground(true);
    machine[5][5]->setStyleSheet("background-color:red");



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
    /*********************************************************************
     * splitting the range of ip address.
     *********************************************************************/
    QProcess ps;
    QString r1=ui->ip1->toPlainText();
                         QString p1=ui->ip2->toPlainText();
                         QRegExp rx("(\\.)");
                         QStringList qy = p1.split(rx);
    QString r2=qy.at(3).toLocal8Bit().constData();
    QString nmap("/bin/sh -c \"nmap -sP "+r1+"-" +r2+"|grep -o '[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}'\"");
    //ui->ot2->setText(nmap);
    ps.start(nmap);
    ps.waitForFinished();
    QString result2=ps.readAllStandardOutput();
    ui->ot->setText(result2);

    /**********************************************
     * calculate no of ip's input by user.
     **********************************************/
     QRegExp rx1("(\\.)");
     QStringList qy1=r1.split(rx1);
     QString dif=qy1.at(3).toLocal8Bit().constData();
     int sub2=r2.toInt();
     int sub1=dif.toInt();
     int diff=sub2-sub1+1;
     QString sub = QString::number(diff);
     ui->display->setText(sub);

     /*******************************************************
      * target ip to be scanned i.e, input ip's of user
      *******************************************************/
     QString nmap1("/bin/sh -c \"nmap -sLP "+r1+"-" +r2+"|grep -o '[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}'\"");
     //ui->ot2->setText(nmap);
     ps.start(nmap1);
     ps.waitForFinished();
     QString total_ip=ps.readAllStandardOutput();
     ui->ot3->setText(total_ip);

    /********************************************************
     * splitting indiviual ip addressess.
     ********************************************************/
     QRegExp rx2("(\\n)");
     QStringList ia=result2.split(rx2);
     QString one=ia.at(0).toLocal8Bit().constData();
     ui->ot2->setText(one);

    /************************************************************
     * compare operation to check for connected and not connected
     ***********************************************************
     if(total_ip.contains(ia.at(1).toLocal8Bit().constData(),Qt::CaseInsensitive)==true)
     {
         ui->ot4->setText("connected");
     }
     else
     {
         ui->ot4->setText("unsuscess");
     }
    */
}
