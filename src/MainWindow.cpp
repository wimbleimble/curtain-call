#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <iostream>
#include <QString>
#include "Cue.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	cueList{ new CueList{} }
{
	ui->setupUi(this);
	connect(ui->actionInsert_Cue, &QAction::triggered,
		this, &MainWindow::insertCue);

	connect(ui->actionRemove_Cue, &QAction::triggered,
		this, &MainWindow::removeCue);

	connect(ui->nextButton, &QPushButton::clicked,
		this, &MainWindow::go);

	connect(ui->stopButton, &QPushButton::clicked,
		this, &MainWindow::panic);

	ui->cueListView->setModel(cueList);
	ui->cueListView->horizontalHeader()->setVisible(true);
}

MainWindow::~MainWindow()
{
	delete cueList;
	delete ui;
}

void MainWindow::insertCue()
{
	int currentSel{ ui->cueListView->selectionModel()->currentIndex().row() };
	cueList->insertRows(currentSel >= 0 ? currentSel : cueList->rowCount(), 1);
}

void MainWindow::removeCue()
{
	int currentSel{ ui->cueListView->selectionModel()->currentIndex().row() };
	if (currentSel >= 0)
		cueList->removeRows(currentSel, 1);
	else
		std::cout << "Nothing selected.\n";
}

void MainWindow::go()
{
	cueList->go();
}

void MainWindow::panic()
{
	cueList->panic();
}