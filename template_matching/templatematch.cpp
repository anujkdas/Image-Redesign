
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main()
{ int i,j,k,l;
	float z;
  Mat a=imread("lena_color.jpg",0);
  Mat b(95,80,CV_8UC1,Scalar(0));
  for (i=0;i<95;i++)
  { for(j=0;j<80;j++)
  	{
  		b.at<uchar>(i,j) = a.at<uchar>(i+75,j+80);
   	}	
  }	
 
   for (i=0;i<a.rows;i++)
  { 
    for(j=0;j<a.cols;j++)
  	{ z=0;
      for(k=0;k<95;k++)
  		{ 
         for(l=0;l<80;l++)
  			 {
              if(i+k<a.rows && j+l<a.cols)
                {
                      z += a.at<uchar>(i+k,j+l) - b.at<uchar>(k,l);
                }
             
         }
  		}
  
if (pow(z,2) < 1)
      {
        cout<<"Yes, i="<<i<<", j="<<j;
        break;
      }
      
    }   
  }

   


}







