#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QPushButton *machine[16][16];

    ~MainWindow();

private slots:
    void on_ping_clicked();

    void on_ping_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
