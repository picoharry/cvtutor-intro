// CVTutor.Intro.Save01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


// Tutorial
// http://docs.opencv.org/3.1.0/db/d64/tutorial_load_save_image.html

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << " Usage: requires image arg." << endl;
		system("pause");
		return -1;
	}

	char* imageName = argv[1];

	Mat image;
	image = imread(imageName, 1);
	if (!image.data)
	{
		cout << " No image data." << endl;
		system("pause");
		return -1;
	}

	Mat gray_image;
	cvtColor(image, gray_image, COLOR_BGR2GRAY);

	// Need to create a folder "saved-images" first.
	cout << " Writing the gray image..." << endl;
	// imwrite("Gray_Image.jpg", gray_image);
	bool suc = imwrite("../../saved-images/Gray_Image.jpg", gray_image);
	cout << " >> Image saved. suc = " + suc << endl;  // ????

	namedWindow(imageName, WINDOW_AUTOSIZE);
	namedWindow("Gray image", WINDOW_AUTOSIZE);

	imshow(imageName, image);
	imshow("Gray image", gray_image);

	waitKey(0);
	return 0;
}
