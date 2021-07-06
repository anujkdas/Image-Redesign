#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int isvalid(int x,int y,int rows,int cols)
{
  if(x<0||y<0||x>=rows||y>=cols)
    return 0;
  return 1;
}
int main()
{ int x,i,j,m,n,y=0,sum=0;
  Mat a = imread("index.jpg",0);
  Mat b(a.rows,a.cols,CV_8UC1,Scalar(255));
  for (i=0;i<a.rows;i++)
    {
    for (j=0;j<a.cols;j++)
      { 
       sum=0;
      if(isvalid(i-1,j-1,a.rows,a.cols))
        sum+= a.at<uchar>(i-1,j-1)/16;
      if(isvalid(i,j-1,a.rows,a.cols))  
        
        sum+= a.at<uchar>(i,j-1)/8;

      if(isvalid(i+1,j-1,a.rows,a.cols))  
        sum+= a.at<uchar>(i+1,j-1)/16;
            
      if(isvalid(i-1,j,a.rows,a.cols))  
        sum+= a.at<uchar>(i-1,j)/8;
      
      if(isvalid(i,j,a.rows,a.cols))  
        sum+= a.at<uchar>(i,j)/4;

      if(isvalid(i+1,j,a.rows,a.cols))  
        sum+= a.at<uchar>(i+1,j)/8;
      
      if(isvalid(i-1,j+1,a.rows,a.cols))  
        sum+= a.at<uchar>(i-1,j+1)/16;
      
      if(isvalid(i,j+1,a.rows,a.cols))  
        sum+= a.at<uchar>(i,j+1)/8;
      
      if(isvalid(i+1,j+1,a.rows,a.cols))  
        sum+= a.at<uchar>(i+1,j+1)/16;

      b.at<uchar>(i,j) = sum;
      }
    }  
  namedWindow("Gauss",WINDOW_NORMAL);
  imshow("Gauss",b);
  waitKey(0);
 }
