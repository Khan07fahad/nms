#ifndef NETMAN_H
#define NETMAN_H

#include <QMainWindow>


namespace Ui {
class Netman;
}

class Netman : public QMainWindow
{
    Q_OBJECT

public:
    explicit Netman(QWidget *parent = 0);
    ~Netman();

private slots:
    void on_ping_clicked();

    void on_output_textChanged();

    void on_stop_clicked();

private:
    Ui::Netman *ui;
};

#endif // NETMAN_H
