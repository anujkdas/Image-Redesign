#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main()
{ int i,j;
	Mat a = imread("fruits.png",1);
  Mat mirror(a.rows,2*a.cols,CV_8UC3,Scalar(255,255,255));
   for(i=0;i<a.rows;++i)
      for(j=0;j<a.cols;++j)
  { 
    mirror.at<Vec3b>(i,j)[0]=a.at<Vec3b>(i,j)[0];
    mirror.at<Vec3b>(i,j)[1]=a.at<Vec3b>(i,j)[1];

    mirror.at<Vec3b>(i,j)[2]=a.at<Vec3b>(i,j)[2];
  }
  
  for(i=0;i<a.rows;++i)
  {
    for(j=a.cols;j<2*a.cols;++j)
    {        
    mirror.at<Vec3b>(i,j)[0]=a.at<Vec3b>(i,2*a.cols-j)[0];
    mirror.at<Vec3b>(i,j)[1]=a.at<Vec3b>(i,2*a.cols-j)[1];
    mirror.at<Vec3b>(i,j)[2]=a.at<Vec3b>(i,2*a.cols-j)[2];      
    }
  }
  namedWindow("window1",WINDOW_NORMAL); 	
  imshow("window1",mirror);	 

	waitKey(0);	}
