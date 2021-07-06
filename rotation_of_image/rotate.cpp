#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main()
{ int i,j,p,q,angle,d_angle=0; 
    Mat a = imread("fruits.png",1);
    Mat b(3*a.rows,3*a.cols,CV_8UC3,Scalar(255,255,255));
    namedWindow("window",WINDOW_NORMAL);
    createTrackbar("Angle","window",&d_angle,360);
    while(1){
             angle = d_angle*3.14/180;
             for(i=a.rows;i<2*a.rows;i++)
               {for(j=a.cols;j<2*a.cols;j++)
                   {p=3*a.rows/2+(i-3*a.rows/2)*cos(angle)+(j-3*a.cols/2)*sin(angle);
                    q=3*a.cols/2-(i-3*a.rows/2)*sin(angle)+(j-3*a.cols/2)*cos(angle);
                    b.at<Vec3b>(p,q) = a.at<Vec3b>(i-a.rows,j-a.cols);
                    }
                }    
              
    imshow("window",b);
        waitKey(1);
        b.setTo(Scalar(255,255,255));
    }
    return 0;   
}          