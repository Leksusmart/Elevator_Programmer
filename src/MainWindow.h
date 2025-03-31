#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "utils.h"
#include "elevator.h"
#include "person.h"

#include <QCloseEvent>
#include <QMainWindow>
#include <cstdlib>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
    MainWindow();
   ~MainWindow();


private:
   Ui::MainWindow *ui;

   private slots:
   void onCompilePressed();
   QString processCode(QString code);
   void closeEvent(QCloseEvent *event) override;

};
#endif // MAINWINDOW_H
