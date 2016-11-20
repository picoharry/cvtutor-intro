// CVTutor.Intro.Capture01.cpp : Defines the entry point for the console application.
//

// Reference:
// http://docs.opencv.org/master/d8/dfe/classcv_1_1VideoCapture.html

#include "stdafx.h"

using namespace cv;
using namespace std;


// Global constants
// const string CAMERA_FEED = "Camera";  // trck, for convenience.
const string WINDOW_NAME = "Display window";


// Usage: CVTutor.Intro.Capture01 <video filename>
int main(int argc, const char* argv[])
{
    // Whether to use a live video feed or a vldeo file.
    auto useCamera = true;

    // Default file name
    // string videoName("../../sample-data/tree.avi");
    string videoName;
    if (argc > 1)
    {
        videoName = argv[1];
    }
    if (!videoName.empty()) {
        useCamera = false;
    }

    // Video capture object
    VideoCapture cap;
    if (useCamera) {
        cap.open(0);
    }
    else {
        cap.open(videoName);
    }

    if (!cap.isOpened())
    {
        cerr << "cannot open camera or video file: " << videoName << endl;
        system("pause");
        return EXIT_FAILURE;
    }

    // Create a window for display.
    namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);

    // Lopp until the video ends or a key is pressed.
    for (;;)
    {
        UMat iFrame, vFrame;
        cap >> iFrame;         // Get a new frame from camera
        if (iFrame.empty()) {  // End of the video file.
            break;
        }

        // Testing:
        // Find edges from the video frame and display the processed image.
        cvtColor(iFrame, vFrame, CV_BGR2GRAY);
        GaussianBlur(vFrame, vFrame, Size(7, 7), 1.5, 1.5);
        Canny(vFrame, vFrame, 0, 30, 3);
        imshow(WINDOW_NAME, vFrame);

        // Wait 200 ms before processing the next frame, or end the loop if a key si pressed.
        if (waitKey(200) >= 0) {
            break;
        }
    }

    return 0;
}
