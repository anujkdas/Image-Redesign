#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main()
{   int i,j,k,max=0,l[256];
	for(i=0;i<256;++i)
		{
			l[i]=0;
			
		}
	Mat a = imread("lowcontrast.PNG",0);
	    for(i=0;i<a.rows;i++)
      {
      	for(j=0;j<a.cols;j++)
      	  {
      	  	k=a.at<uchar>(i,j);
      	  	l[k]+=1;            
      	  }
 
      }
      for(i=0;i<256;i++)
		{
		if(l[i]>max)
			max=l[i];
	    }
     Mat histo(max+1,256,CV_8UC1,Scalar(255));
     for(k=0;k<256;k++)
     {
   	   for(i=max;i>=(max-l[k]);i--)
   	   {    
   	   	 	histo.at<uchar>(i,k ) = 0;      
   	   }

     }
 namedWindow("window1",WINDOW_NORMAL);
 imshow("window1",histo);	 

					waitKey(0);

 }