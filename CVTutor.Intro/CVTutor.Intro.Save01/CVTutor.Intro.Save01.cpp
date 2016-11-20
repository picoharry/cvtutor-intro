// CVTutor.Intro.Save01.cpp : Defines the entry point for the console application.
//

// Tutorial
// http://docs.opencv.org/3.1.0/db/d64/tutorial_load_save_image.html

#include "stdafx.h"

using namespace cv;
using namespace std;

// Global contstants
const string WINDOW_ORIGINAL_IMAGE = "Original image window";
const string WINDOW_GRAY_IMAGE = "Gray image window";


int main(int argc, const char* argv[])
{
    // Default file name
    string imageName("../../sample-data/HappyFish.jpg");
    if (argc > 1)
    {
        imageName = argv[1];
    }

    // Load the image.
    Mat image = imread(imageName, -1);
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        system("pause");
        return -1;
    }

    // Create GUI Windows.
    namedWindow(WINDOW_ORIGINAL_IMAGE, WINDOW_AUTOSIZE);
    namedWindow(WINDOW_GRAY_IMAGE, WINDOW_AUTOSIZE);

    // Get a UMat
    UMat uImg = image.getUMat(ACCESS_READ);

    // Display the original image.
    imshow(WINDOW_ORIGINAL_IMAGE, uImg);

    // Convert it into gray.
    UMat uGray;
    cvtColor(uImg, uGray, COLOR_BGR2GRAY);

    // Display the converted gray image.
    imshow(WINDOW_GRAY_IMAGE, uGray);

    // Save the gray image.
    // Note: Need to create a folder named "saved-images" first (as a sibling to sample-data).
    cout << " Writing the gray image..." << endl;
    bool suc = imwrite("../../saved-images/Gray_Image.jpg", uGray);
    cout << " >> Image saved. suc = " << suc << endl;  // ????

    // Wait for a keystroke in the window
    waitKey(0);
    return 0;
}
