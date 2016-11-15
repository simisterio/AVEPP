#ifndef MAT2QIMAGE_H
#define MAT2QIMAGE_H

#include <QImage>
#include <opencv2/opencv.hpp>
#include <QDebug>

using namespace cv;

QImage MatToQImage(const Mat& mat);

#endif // MAT2QIMAGE_H
