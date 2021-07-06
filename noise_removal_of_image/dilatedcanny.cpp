#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main()
{ int x,i,j,m,n;
  Mat a = imread("erosion.png",0);
  Mat b(a.rows,a.cols,CV_8UC1,Scalar(255));
  for (i=0;i<=a.rows;i++)
    {
    for (j=0;j<=a.cols;j++)
    { 
      for (m=i-1;m<=i+1;m++)
        { for (n=j-1;n<=j+1;n++)
           { x=a.at<uchar>(m,n);
            if (x==0 && i>1 && j>1) 
             b.at<uchar>(i,j) =0;
   }
  }
  }
  }

   namedWindow("window1",WINDOW_NORMAL);  
   
    while(1)
   {
     Mat c(a.rows,a.cols,CV_8UC1,Scalar(255));
     Canny(b,c,255,2*255,3);

      imshow("window1",c);   

          waitKey(1);
        }}