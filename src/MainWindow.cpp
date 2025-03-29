#include "MainWindow.h"
#include "Elevator.h"
#include "src/ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   connect(ui->pushButton_Compile, &QPushButton::clicked, this, &MainWindow::onCompilePressed);

   Elevator elevator1(0,0);
   //TODO: отрисовать лифт на экране
   Elevator elevator2(1,1);
}
void MainWindow::onCompilePressed()
{
    QString code = processCode(ui->CodeText->toPlainText());
    qDebug() << code;
}
QString MainWindow::processCode(QString code)
{
    code.replace("\n", " ");
    code.replace("\t", " ");

    return code;
}
MainWindow::~MainWindow()
{
   delete ui;
}
