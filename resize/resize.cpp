#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main()
{   int i,j,x,y,z,m,l,p = 0,q =0,r = 0;

	Mat a =imread("fruits.png",1);
	Mat b(1200,1200,CV_8UC3,Scalar(255,255,255));
	Mat c(400,400,CV_8UC3,Scalar(255,255,255));

    for (i=0;i<300;i++)
    {	     
            for (j=0;j<300;j++)
            {
                x=a.at<Vec3b>(i,j)[0]; 
        		y=a.at<Vec3b>(i,j)[1]; 
        		z=a.at<Vec3b>(i,j)[2];

            for (l=0;l<4;l++)

            {
                for (m=0;m<4;m++) 
                { 	if(4*i+l<1200&&4*i+m<1200)
                    {b.at<Vec3b>(4*i+l,4*j+m)[0] = x;
                     b.at<Vec3b>(4*i+l,4*j+m)[1] = y;
                     b.at<Vec3b>(4*i+l,4*j+m)[2] = z;
    		     }}
            } 
            }
    }                
               for (i=0;i<400;i++)
    	       {
                    for(j=0;j<400;j++)
                    { p = 0;
                        q=0;
                        r=0;
                                 
                            for(l=0;l<3;l++)
                            {
                                for(m=0;m<3;m++)
                                   {  if(3*i+l<1200&&3*i+m<1200)
                                      p+=  b.at<Vec3b>(3*i+l,3*j+m)[0] ;
                                      q+=  b.at<Vec3b>(3*i+l,3*j+m)[1] ;
                                      r+=  b.at<Vec3b>(3*i+l,3*j+m)[2] ;
                                   }
                            }       


                            c.at<Vec3b>(i,j)[0]=p/9;
                            c.at<Vec3b>(i,j)[1]=q/9;
                            c.at<Vec3b>(i,j)[2]=r/9;
                     }
               }     

         namedWindow("window1",WINDOW_AUTOSIZE);
    	 imshow("window1",c); 
         
         waitKey(0);	
     }

                                                                    
    