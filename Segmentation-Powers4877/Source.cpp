#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat manGray = imread("../OTSU2/andreas_L-150x150.png",IMREAD_GRAYSCALE);
	Mat manRGB = imread("../OTSU2/andreas_L-150x150.png");

	Mat test;
	
	Mat img_bw = manGray > 120;
	
	namedWindow("Test");
	threshold(manGray, img_bw, 0, 255, THRESH_BINARY | THRESH_OTSU);
	pyrMeanShiftFiltering(manRGB, test, 5,10);
	imshow("Test", test);
	waitKey(0);
}