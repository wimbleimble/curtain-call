#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cueList{ new CueList{} }
{
    ui->setupUi(this);
    
    ui->cueListView->setModel(cueList);
    ui->cueListView->horizontalHeader()->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete cueList;
    delete ui;
}
