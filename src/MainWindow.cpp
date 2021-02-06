#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QString>
#include "Cue.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cueList{ new CueList{} }
{
    ui->setupUi(this);

    for (int iii{ 0 }; iii <= 4; ++iii)
    {
        cueList->addCue(Cue{QString{ iii }, "oopdoop", "oopypoopy"});
    }
    
    ui->cueListView->setModel(cueList);
    ui->cueListView->horizontalHeader()->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete cueList;
    delete ui;
}
