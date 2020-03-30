#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	String sWindowName;

	/*
	OTSU 2
	*/
	Mat mMan = imread("../OTSU2/andreas_L-150x150.png");
	Mat manGray = imread("../OTSU2/andreas_L-150x150.png", IMREAD_GRAYSCALE);

	Mat mEdge = imread("../OTSU2/edge_L-150x150.png");
	Mat mEdgeGray = imread("../OTSU2/edge_L-150x150.png", IMREAD_GRAYSCALE);

	Mat mSouth = imread("../OTSU2/south_L-150x150.png");
	Mat mSouthGray = imread("../OTSU2/south_L-150x150.png", IMREAD_GRAYSCALE);
	
	Mat mOTSU2;
	
	threshold(manGray, mOTSU2, 0, 255, THRESH_BINARY | THRESH_OTSU);

	sWindowName = "Man - Original";
	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mMan);

	sWindowName = "Man - Otsu";
	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mOTSU2);
	waitKey(0);

	destroyAllWindows();

	threshold(mEdgeGray, mOTSU2, 0, 255, THRESH_BINARY | THRESH_OTSU);

	sWindowName = "Edge - Original";
	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mEdge);

	sWindowName = "Edge - Otsu";
	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mOTSU2);
	waitKey(0);

	destroyAllWindows();

	threshold(mSouthGray, mOTSU2, 0, 255, THRESH_BINARY | THRESH_OTSU);

	sWindowName = "South - Original";
	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mSouth);

	sWindowName = "South - Otsu";
	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mOTSU2);
	waitKey(0);

	destroyAllWindows();

	/*
	OTSU Multiple
	*/
	Mat mBlocks = imread("../OTSUMulti/blocks_L-150x150.png");
	Mat mStanding = imread("../OTSUMulti/blocks_L-150x150.png");
	Mat mBuilding = imread("../OTSUMulti/S04-150x150.png");
	Mat mPark = imread("../OTSUMulti/S05-150x150.png");


	/*
	Mean Shift Segmentation
	*/
	Mat mManBench = imread("../MS/S00-150x150.png");
	Mat mRoadCurve = imread("../MS/S02-150x150.png");
	Mat mStatueBench = imread("../MS/S03-150x150.png");
	Mat mRoad = imread("../MS/set1Seq2_L-150x150.png");
	Mat mCar = imread("../MS/set2Seq1_L-150x150.png");

	Mat mMS;

	sWindowName = "Man on Bench - Original";
	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mManBench);
	
	sWindowName = "Man on Bench - MS";
	namedWindow(sWindowName, WINDOW_NORMAL);
	pyrMeanShiftFiltering(mManBench, mMS, 10, 20);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mMS);
	waitKey(0);
	
	destroyAllWindows();
	
	sWindowName = "Road Curve - Original";
	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mRoadCurve);
	
	sWindowName = "Road Curve - MS";
	namedWindow(sWindowName, WINDOW_NORMAL);
	pyrMeanShiftFiltering(mRoadCurve, mMS, 10, 20, 2);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mMS);
	waitKey(0);
	
	destroyAllWindows();
	
	sWindowName = "Statue on Bench - Original";
	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mStatueBench);
	
	sWindowName = "Statue on Bench - MS";
	namedWindow(sWindowName, WINDOW_NORMAL);
	pyrMeanShiftFiltering(mStatueBench, mMS, 15, 25);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mMS);
	waitKey(0);
	
	destroyAllWindows();
	
	sWindowName = "Road - Original";
	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mRoad);
	
	sWindowName = "Road - MS";
	namedWindow(sWindowName, WINDOW_NORMAL);
	pyrMeanShiftFiltering(mRoad, mMS, 10, 20, 1);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mMS);
	waitKey(0);
	
	destroyAllWindows();
	
	sWindowName = "Car on Road - Original";
	namedWindow(sWindowName, WINDOW_NORMAL);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mCar);
	
	sWindowName = "Car on Road - MS";
	namedWindow(sWindowName, WINDOW_NORMAL);
	pyrMeanShiftFiltering(mCar, mMS, 20, 40, 2);
	resizeWindow(sWindowName, 300, 300);
	imshow(sWindowName, mMS);
	waitKey(0);
}