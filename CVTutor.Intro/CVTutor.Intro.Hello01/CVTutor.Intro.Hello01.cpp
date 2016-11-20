// CVTutor.Intro.Hello01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace cv;
using namespace std;

// Global constants
const string WINDOW_NAME = "Display window";


// Usage: CVTutor.Intro.Hello01
int main(int argc, const char* argv[])
{
    // Create a window for display.
    namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);

    // Create a uniform color UMat.
    UMat uImg(270, 480, CV_8UC3, Scalar(255, 0, 0));

    // Hello OpenCV!
    putText(uImg, "Hello OpenCV!", cv::Point(40, 80), FONT_HERSHEY_SIMPLEX, 1.5, cv::Scalar(0, 255, 128));

    // Show the image inside it.
    imshow(WINDOW_NAME, uImg);

    // Wait for a keystroke in the window
    waitKey(0);
    return 0;
}
