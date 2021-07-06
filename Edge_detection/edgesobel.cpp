#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<cmath>
using namespace std;
using namespace cv;

int main()
{
	Mat a = imread("rubik.jpg",0);
	Mat n(a.rows,a.cols,CV_8UC1,Scalar(255));
	Mat k(a.rows+2,a.cols+2,CV_8UC1,Scalar(255));

	int i,j,x,y;
	float sx,sy,st;
	int tt = 0,tx=0,ty=0;

	for (i=0;i<a.rows;i++)
	{
		for (j=0;j<a.cols;j++)
		{
			k.at<uchar>(i+1,j+1)=a.at<uchar>(i,j);
		}
	}

	namedWindow("window1",WINDOW_NORMAL);
	createTrackbar("tt","window1",&tt,600);
	createTrackbar("tx","window1",&tx,600);
	createTrackbar("ty","window1",&ty,600);

	while(1){
			Mat n(a.rows,a.cols,CV_8UC1,Scalar(255));

		for (i=1;i<a.rows+1;i++)
		{
			for (j=1;j<a.cols+1;j++)
			{
				sx = (k.at<uchar>(i-1,j-1))*(-1)+(k.at<uchar>(i-1,j+1))*(-1)+(k.at<uchar>(i-1,j))*(-2)+(k.at<uchar>(i+1,j-1))*(1)+(k.at<uchar>(i+1,j+1))*(1)+(k.at<uchar>(i+1,j))*(2);
				sy = (k.at<uchar>(i-1,j-1))*(-1)+(k.at<uchar>(i+1,j-1))*(-1)+(k.at<uchar>(i,j-1))*(-2)+(k.at<uchar>(i-1,j+1))*(1)+(k.at<uchar>(i+1,j+1))*(1)+(k.at<uchar>(i,j+1))*(2);
				st = sqrt((sx*sx) + (sy*sy));
				if (st>tt||sx>tx||sy>ty)
				{
				n.at<uchar>(i-1,j-1) = 0;
				}
			 }
	   }
		imshow("window1",n);
		waitKey(1);
	}


}