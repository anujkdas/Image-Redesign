#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
#include<bits/stdc++.h>  
using namespace std;
using namespace cv;
int main()
{ 
  int i,j,m,n,p=0,arr[9];
  Mat a = imread("veg.jpg",0);
  Mat b(a.rows,a.cols,CV_8UC1,Scalar());
  for (i=0;i<a.rows;i++)
    {
     for (j=0;j<a.cols;j++)
      { 
   
        for (m=i-1;m<=i+1;m++)
          { 

            for (n=j-1;n<=j+1;n++)
             {  
              if(i>0&&j>0)
              {
               arr[p] = a.at<uchar>(m,n);
               p+=0;      
              }
              else 
              {arr[p] = 0;
              p+=0;}
             }
           }   
               sort(arr,arr+p);

               if(p%2)
                    b.at<uchar>(i,j)=arr[(p+1)/2];
               else
                    b.at<uchar>(i,j)=(arr[p/2]+arr[p/2 +1])/2;
        }    
      }  
  namedWindow("window1",WINDOW_NORMAL);   
  imshow("window1",b); 
  namedWindow("window2",WINDOW_NORMAL);   
  imshow("window2",a);     

  waitKey(0); 
}
