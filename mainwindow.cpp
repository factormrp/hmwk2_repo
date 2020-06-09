#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton, SIGNAL( released() ),
                     this, SLOT( intermediary(int) ) );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::intermediary(int value)
{
    value++;
    updateScore();
    return;
}

void MainWindow::updateScore() const
{
    double hw1 = static_cast<double>(ui->hw1->value());
    double hw2 = static_cast<double>(ui->hw2->value());
    double hw3 = static_cast<double>(ui->hw3->value());
    double hw4 = static_cast<double>(ui->hw4->value());
    double hw5 = static_cast<double>(ui->hw5->value());
    double hw6 = static_cast<double>(ui->hw6->value());
    double hw7 = static_cast<double>(ui->hw7->value());
    double hw8 = static_cast<double>(ui->hw8->value());
    double midterm1 = static_cast<double>(ui->midterm1->value());
    double midterm2 = static_cast<double>(ui->midterm2->value());
    double final = static_cast<double>(ui->spinBox_11->value());

    double hw_percent = 25*((hw1+hw2+hw3+hw4+hw5+hw6+hw7+hw8)/160.0);
    double midterm_percent_1 = 20*(midterm1/100.0)+ 20*(midterm2/100.0);
    double midterm_percent_2 = 30*(qMax(midterm1,midterm2)/100.0);
    double final_percent_1 = 35*(final/100.0);
    double final_percent_2 = 45*(final/100.0);

    double score1 = hw_percent + midterm_percent_1 + final_percent_1;
    double score2 = hw_percent + midterm_percent_2 + final_percent_2;

    double output = static_cast<double>(qMax(score1, score2));

    QString text(QString::number(output));
    ui->label_Score_2->setText(text);
}
