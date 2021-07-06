
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main()
{   int tx;
	Mat a = imread("rubik.jpg",1);
	
    namedWindow("window1",WINDOW_NORMAL); 	
    createTrackbar("tx","window1",&tx,255);
    while(1)
   {
     Mat c(a.rows,a.cols,CV_8UC1,Scalar(0));
   	 GaussianBlur(a, c ,Size(3, 3),200);

   		imshow("window1",c);	 

					waitKey(1);
	}}
	