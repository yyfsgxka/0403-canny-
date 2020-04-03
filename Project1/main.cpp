#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	//练习一 canny算子
	//读取摄像头图像，并对摄像头图像进行中值滤波
	VideoCapture cap;//实例化一个videocapture类，名称为cap
	cap.open(0);//
	if (!cap.isOpened())
	{
		std::cout << "不可打开视频文件" << std::endl;
		return -1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		Mat frame,rframe,dx,dy,abs_dx,abs_dy;
		Mat Canny1, Canny2;
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "不能从视频中读取帧" << std::endl;
			break;
		}
		else
		{
			cvtColor(frame, rframe, CV_RGB2GRAY);
			//sobel边缘提取函数
			Sobel(rframe, dx, CV_16SC1, 1, 0, 3);
			convertScaleAbs(dx, abs_dx);
			Sobel(rframe, dy, CV_16SC1, 1, 0, 3);
			convertScaleAbs(dy, abs_dy);
			//canny算子（1）
			Canny(dx, dy, Canny1,100 ,300, false);
			imshow("Canny1", Canny1);
			//Canny算子（2）
			Canny(frame, Canny2, 80, 240, 3, false);
			imshow("Canny2", Canny2);
			imshow("frame", frame);
		}
		waitKey(30);

	}
	return 0;



}