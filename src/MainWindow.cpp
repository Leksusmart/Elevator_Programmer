#include "MainWindow.h"
#include "src/ui_MainWindow.h"

std::vector<Elevator*> elevator(MAXSHAFT+1);
std::vector<QLabel *> label_elevator(MAXSHAFT+1);
std::vector<QLabel *> people;

MainWindow::MainWindow()
    : QMainWindow()
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(static_cast<int>(time(NULL)));

    connect(ui->pushButton_Compile, &QPushButton::clicked, this, &MainWindow::onCompilePressed);

    for (int i = 0; i < MAXSHAFT; ++i){
        int randFloor = rand() % (abs(MINFLOOR)+MAXFLOOR+1) - MINFLOOR;
        elevator[i] = new Elevator(i, randFloor, ui->GameArea);
    }
    for (int i = 0; i < 50; ++i) {
        int randFloor = rand() % (abs(MINFLOOR)+MAXFLOOR+1) - MINFLOOR;
        new Person(randFloor, ui->GameArea);
    }
}
void MainWindow::onCompilePressed()
{
    QString code = processCode(ui->CodeText->toPlainText());
    qDebug() << code;
    if (code.contains("move")) {
        int i = code.indexOf("move");
        if (code[i + 4 + 1].isDigit()) {
            int shaft = QString(code[i + 4 + 1]).toInt();
            if (code[i + 4 + 3].isDigit()) {
                int floor = QString(code[i + 4 + 3]).toInt();
                if (elevator.size() > shaft) {
                    elevator[shaft]->goToFloor(floor);
                }
            }
        }
    }
}
QString MainWindow::processCode(QString code)
{
    code.replace("\n", " ");
    code.replace("\t", " ");

    return code;
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "Closing MainWindow";
    event->accept();
}
MainWindow::~MainWindow()
{
    for (Elevator* value : elevator) {
        if(value != nullptr)delete value;
    }
    for (QLabel* value : label_elevator) {
        if(value != nullptr)delete value;
    }
    for (QLabel *value : people) {
        if(value != nullptr)delete value;
    }
   delete ui;
}
