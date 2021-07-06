#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
using namespace cv;
int main()
{   int i,j,x,y,z;
	Mat a = imread("fruits.png",1);
	Mat method1(a.rows,a.cols,CV_8UC1,Scalar());
        Mat method2(a.rows,a.cols,CV_8UC1,Scalar());
        Mat method3(a.rows,a.cols,CV_8UC1,Scalar());
    for (i=0;i<=a.rows;i++)
    {
    for (j=0;j<=a.cols;j++)
    {   x=a.at<Vec3b>(i,j)[0];
     	y=a.at<Vec3b>(i,j)[1];
        z=a.at<Vec3b>(i,j)[2];
        method1.at<uchar>(i,j) =x/3+y/3+z/3;
        
        method3.at<uchar>(i,j) =0.07*x+0.21*y+0.72*z;
        int arr[] = {x,y,z};
        sort(arr,arr+3);
        method2.at<uchar>(i,j) = arr[0]/2+arr[2]/2;
     }

     }

       namedWindow("window1",WINDOW_NORMAL); 	
       imshow("window1",method1);
       namedWindow("window2",WINDOW_NORMAL); 	
       imshow("window2",method2);
       namedWindow("window3",WINDOW_NORMAL); 	
       imshow("window3",method3);	 

	waitKey(0);	}
