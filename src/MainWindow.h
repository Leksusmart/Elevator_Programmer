#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   MainWindow(QWidget *parent = nullptr);
   ~MainWindow();

   QPixmap personImage = QPixmap("://images/person.png").scaled(55,100,Qt::KeepAspectRatio,Qt::SmoothTransformation);
   QPixmap elevatorImage = QPixmap("://images/Elevator.png").scaled(100,100,Qt::KeepAspectRatio,Qt::SmoothTransformation);
private:
   Ui::MainWindow *ui;

   private slots:
   void onCompilePressed();
   QString processCode(QString code);
};
#endif // MAINWINDOW_H
