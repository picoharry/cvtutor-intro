// CVTutor.Intro.Load01.cpp : Defines the entry point for the console application.
//

// Tutorial:
// http://docs.opencv.org/3.1.0/db/deb/tutorial_display_image.html

#include "stdafx.h"

using namespace cv;
using namespace std;

// Global constants
const string WINDOW_NAME = "Display window";


// Usage: CVTutor.Intro.Load01 <image filename>
int main(int argc, const char* argv[])
{
    // Default file name
    string imageName("../../sample-data/HappyFish.jpg");
    if (argc > 1)
    {
        imageName = argv[1];
    }

    // Load the image.
    Mat image = imread(imageName, IMREAD_COLOR);
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        system("pause");
        return -1;
    }

    // Convert it into a UMat
    UMat uImg = image.getUMat(ACCESS_READ);

    // Create a window for display.
    namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);

    // Show the image inside it.
    imshow(WINDOW_NAME, uImg);

    // Wait for a keystroke in the window
    waitKey(0);
    return 0;
}
