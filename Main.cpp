#include "highgui.h"  
#include <cstring>
#include <cstdio>

int main(int argc,char* argv[])  
{  
	int i = 0;
	char *outputFileNamePre = "F:\\vs\\样本2\\1\\";
	char temp[20] = {0};
	char outputFileName[512] = {0};
	CvCapture* capture = cvCreateFileCapture( "F:\\vs\\样本2\\白天\\192.168.200.51_01_0_20160802_003325_1.avi");  

	IplImage* frame;

	while(1)  
	{  
		frame = cvQueryFrame(capture);  
		if(!frame)
			break ;

		strcpy(outputFileName, outputFileNamePre);
		sprintf(temp, "%d.jpg", ++i);
		strcat(outputFileName, temp);
		if(!(i%4))
		cvSaveImage( outputFileName, frame);  
		/*char c = cvWaitKey(1);  

		if(c == 27)  
			break;  */
	}  
	cvReleaseCapture(&capture);  

	return 0;  
}  