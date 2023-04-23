#ifndef CRACK_HPP
#define CRACK_HPP

// #include "MainScreen.hpp"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>

class Crack : public QWidget
{
public:
    Crack(QWidget *parent = nullptr, QStackedWidget *stackedWidget = nullptr);

    //function:
    void returnToMain();

private slots:
    void on_returnButton_clicked();

private:
    QStackedWidget *stackedWidget;
    QLabel* imageLabel;
    QPushButton* returnButton;
};

#endif // SCREEN1_HPP
