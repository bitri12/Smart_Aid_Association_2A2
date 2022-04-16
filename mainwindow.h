#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Employee.h"
#include <QMainWindow>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pb_supp_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pb_modifier_clicked();


    void on_pushButton_5_clicked();

    void on_Recherche_employee_clicked();
    void on_PDF_clicked();
    void on_recherche_CIN_clicked();


    //historique
void ouvriremploye();

void on_pushButtonHisto_clicked();


private:
    Ui::MainWindow *ui;
    Employee tmpEmployee;
    Employee aff;
    QSystemTrayIcon *mSystemTrayIcon;
    QImage img;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOptionMenu;
    QAction *mAllumerAction;
    QAction *mEteindreAction;
    QAction *mCapturerAction;
};
#endif // MAINWINDOW_H
