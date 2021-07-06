#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main()
{  int t,i,j,x,y,z,colour,count =0;
   float r;
   
	Mat a = imread("A1.png",0);
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
    for (i=0;i<=a.rows;i++)
    {
      for (j=0;j<=a.cols;j++)
      {  
         x=a.at<uchar>(i,j);
         
         if (x<120)

         b.at<uchar>(i,j) =0;
       else 
         b.at<uchar>(i,j) =255;
     
      }
    }

            Mat graph(2*sqrt(a.rows*a.rows+a.cols*a.cols)+1,1000,CV_8UC1,Scalar(0));

      for (i=0;i<a.rows;i++)
    {
      for (j=0;j<a.cols;j++)
         {

           if(b.at<uchar>(i,j)==255)
           {
            for(t=0;t<180;t++)
             {
               r=(i)*cos(t*3.14/180)+j*sin(t*3.14/180);
               if(graph.at<uchar>(r+sqrt(a.rows*a.rows+a.cols*a.cols),t)<250)
               graph.at<uchar>(r+sqrt(a.rows*a.rows+a.cols*a.cols),t) += 2 ;
            }
          }
         }  
    }
    
  
  /* for (t=0;t<900;t++)
    {+sqrt(a.rows*a.rows+a.cols*a.cols))+=2;       
               continue;  
      for (r=0;r<=sqrt(a.rows*a.rows+a.cols*a.cols);r++)
      {       
         if (graph.at<uchar>(r,t) >=50)
        { count+=1;}
         cout<<"count";




            Mat graph(2*sqrt(a.rows*a.rows+a.cols*a.cols)+1,1000,CV_8UC1,Scalar(0));

      for (i=0;i<a.rows;i++)
    {
      for (j=0;j<a.cols;j++)
         { 
           if(b.at<uchar>(i,j) =255)
           {
            for(t=0;t<180;t++)
             {
               r=i*cos(t*3.14/180)+j*sin(t*3.14/180);
               if(graph.at<uchar>(t,r+sqrt(a.rows*a.rows+a.cols*a.cols))<250)
               graph.at<uchar>(t,r+sqrt(a.rows*a.rows+a.cols*a.cols)) += 2;
            }}
         }  
    }...............
      }
    }
  */

  namedWindow("window1",WINDOW_NORMAL); 	
	imshow("window1",graph);	
  
   
	waitKey(0);	}