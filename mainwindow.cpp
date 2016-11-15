#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mat2qimage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <QLabel>


using namespace cv;
using namespace std;
using namespace cv::xfeatures2d;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    salida1 = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_casco_clicked()
{
    //load training image
    Mat object = imread ("/home/pedro/PDI-OPENCV/SURF_6/CASCO_opt.png", CV_LOAD_IMAGE_GRAYSCALE);
    double t; //timing variable

    //SURF Detector, and descriptor parameters
    int minHess=2000;
    vector<KeyPoint> kpObject, kpImage;
    Mat desObject, desImage;

    //SURF Detector, and descriptor parameters, match object initialization
    Ptr<SURF> detector = SURF::create( minHess );
    detector->detectAndCompute( object, Mat(), kpObject, desObject );
    //SurfFeatureDetector detector(minHess);
    //detector.detect(object, kpObject);
    //SurfDescriptorExtractor extractor;
    //extractor.compute(object, kpObject, desObject);

    FlannBasedMatcher matcher;

    //Initialize video and display window
    VideoCapture cap(0);  //camera 0 is webcam

    //Object corner points for plotting box
    vector<Point2f> obj_corners(4);
    obj_corners[0] = cvPoint(0,0);
    obj_corners[1] = cvPoint( object.cols, 0 );
    obj_corners[2] = cvPoint( object.cols, object.rows );
    obj_corners[3] = cvPoint( 0, object.rows );

    //video loop
    char escapeKey='k';
    double frameCount = 0;
    float thresholdMatchingNN=0.7;
    unsigned int thresholdGoodMatches=4;
    unsigned int thresholdGoodMatchesV[]={4,5,6,7,8,9,10};

    for (int j=0; j<7;j++){
        thresholdGoodMatches=thresholdGoodMatchesV[j];
        //thresholdGoodMatches=8;
        cout<<thresholdGoodMatches<<endl;

    if(true)
    {
        t = (double)getTickCount();
    }

    while (escapeKey != 'q')
    {
        frameCount++;
        Mat frame;
        Mat image;
        cap>>frame;
        cvtColor(frame, image, CV_RGB2GRAY);

        Mat des_image, img_matches, H;
        vector<KeyPoint> kp_image;
        vector<vector<DMatch > > matches;
        vector<DMatch > good_matches;
        vector<Point2f> obj;
        vector<Point2f> scene;
        vector<Point2f> scene_corners(4);

        detector->detectAndCompute( image, Mat(), kp_image, des_image );
        //detector.detect( image, kp_image );
        //extractor.compute( image, kp_image, des_image );

        if(kp_image.size()>=2 && kpObject.size()>=2)
        {
            matcher.knnMatch(desObject, des_image, matches, 2);
        }

        for(int i = 0; i < min(des_image.rows-1,(int) matches.size()); i++) //THIS LOOP IS SENSITIVE TO SEGFAULTS
        {
            if((matches[i][0].distance < thresholdMatchingNN*(matches[i][1].distance)) && ((int) matches[i].size()<=2 && (int) matches[i].size()>0))
            {
                good_matches.push_back(matches[i][0]);
            }
        }

        //if (good_matches.size()<1)
        //	good_matches.resize(0,cv::DMatch);

        //Draw only "good" matches
        drawMatches( object, kpObject, image, kp_image, good_matches, img_matches, Scalar::all(-1), Scalar::all(-1), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

        if (good_matches.size() >= thresholdGoodMatches)
        {
            //Display that the object is found
            putText(img_matches, "Elemento Encontrado", cvPoint(10,50),FONT_HERSHEY_COMPLEX_SMALL, 2, cvScalar(0,0,250), 1, CV_AA);
            for(unsigned int i = 0; i < good_matches.size(); i++ )
            {
                //Get the keypoints from the good matches
                obj.push_back( kpObject[ good_matches[i].queryIdx ].pt );
                scene.push_back( kp_image[ good_matches[i].trainIdx ].pt );
            }

            H = findHomography( obj, scene, CV_RANSAC );

//            perspectiveTransform( obj_corners, scene_corners, H);

//            //Draw lines between the corners (the mapped object in the scene image )
//            line( img_matches, scene_corners[0] + Point2f( object.cols, 0), scene_corners[1] + Point2f( object.cols, 0), Scalar(0, 255, 0), 4 );
//            line( img_matches, scene_corners[1] + Point2f( object.cols, 0), scene_corners[2] + Point2f( object.cols, 0), Scalar( 0, 255, 0), 4 );
//            line( img_matches, scene_corners[2] + Point2f( object.cols, 0), scene_corners[3] + Point2f( object.cols, 0), Scalar( 0, 255, 0), 4 );
//            line( img_matches, scene_corners[3] + Point2f( object.cols, 0), scene_corners[0] + Point2f( object.cols, 0), Scalar( 0, 255, 0), 4 );
        }
        else
        {
            putText(img_matches, "", cvPoint(10,50), FONT_HERSHEY_COMPLEX_SMALL, 3, cvScalar(0,0,250), 1, CV_AA);
        }

        //Show detected matches
        //imshow( "Good Matches", img_matches );

        cv::resize(img_matches, img_matches,cv::Size(850,630));
        salida1 = new QImage(MatToQImage(img_matches));
        QLabel *label1 = new QLabel;
        label1->setPixmap(QPixmap::fromImage(*salida1, Qt::AutoColor));
        ui->scrollArea_Video->setWidget(label1);

        escapeKey=cvWaitKey(10);
        //imwrite("/home/pedro/PDI-OPENCV/SURF_6/bookIP3.jpg", img_matches);

//        if(frameCount>10)
//           escapeKey='q';
    }

    //average frames per second
    if(true)
    {
        t = ((double)getTickCount() - t)/getTickFrequency();
        cout<<t<<" "<<frameCount/t<<endl;
        cvWaitKey(0);
    }

    frameCount=0;
    escapeKey='a';
    }

    //Release camera and exit
    cap.release();
    //return 0;


}

void MainWindow::on_Button_guantes_clicked()
{

}

void MainWindow::on_Button_mascara_clicked()
{

}

void MainWindow::on_Button_chaleco_clicked()
{

}



void MainWindow::on_Button_salir_clicked()
{
    qApp->quit();
}

void MainWindow::on_Button_reset_clicked()
{

}

void MainWindow::on_Button_tipo_trabajo_clicked()
{

}
