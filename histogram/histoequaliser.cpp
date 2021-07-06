#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main()
{  int l[256],max=0,sum[256], i,j,k;
	float S_;
	int S;
	for(i=0;i<256;++i)
		{
			l[i]=0;
			
		}

    Mat a = imread("images (40).jpeg",0);
    Mat b(a.rows,a.cols,CV_8UC1,Scalar());
    for(i=0;i<a.rows;i++)
       {
      	for(j=0;j<a.cols;j++)
      	  {
      	  	k=a.at<uchar>(i,j);
      	  	l[k]+=1;            
      	  }
      }
    for(k=1;k<256;k++)
    { 
    	sum[0] = 0;
        sum[k] = sum[k-1] + l[k];
    }


    S_=(255*sum[255]/(a.rows*a.cols))+ 0.5 ;
    S=S_;
    for(i=0;i<a.rows;i++)
      {
      	for(j=0;j<a.cols;j++)
      	  {
    b.at<uchar>(i,j) = S*a.at<uchar>(i,j);
	}}
    

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
 namedWindow("window2",WINDOW_NORMAL);
    imshow("window2",b);	 
 
			 

					waitKey(0);

 } 






 /*
   
	
	
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
 namedWindow("window2",WINDOW_NORMAL);
    imshow("window2",b);	 
 
			 

					waitKey(0);

 } 
*/












