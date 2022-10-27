#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <auth.h>
#include <QTextCharFormat>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action, SIGNAL(triggered()), this, SLOT(About_Lab1()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::About_Lab1()
{
    auth * dg = new auth();
    dg->show();
}



void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(prevIndex + 1), f);
    QTextCharFormat format;
    f = ui->calendarWidget->weekdayTextFormat(Qt::DayOfWeek(index + 1));
    prevIndex = index;
    ui->calendarWidget->setFirstDayOfWeek(Qt::DayOfWeek(index + 1));
    format.setForeground(qvariant_cast<QColor>("green"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(index + 1), format);
}
