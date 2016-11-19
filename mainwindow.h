#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mat2qimage.h"
#include <QImage>
#include <opencv2/opencv.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
     QImage *salida1;
     cv::Mat img_matches;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Button_casco_clicked();
    void on_Button_guantes_clicked();
    void on_Button_mascara_clicked();
    void on_Button_chaleco_clicked();
    void on_Button_salir_clicked();
    void on_Button_reset_clicked();
    void on_Button_tipo_trabajo_clicked();
    void analizador(Mat);
signals:
    void surf_listo(Mat);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
