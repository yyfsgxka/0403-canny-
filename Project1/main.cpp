#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	//��ϰһ canny����
	//��ȡ����ͷͼ�񣬲�������ͷͼ�������ֵ�˲�
	VideoCapture cap;//ʵ����һ��videocapture�࣬����Ϊcap
	cap.open(0);//
	if (!cap.isOpened())
	{
		std::cout << "���ɴ���Ƶ�ļ�" << std::endl;
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
			std::cout << "���ܴ���Ƶ�ж�ȡ֡" << std::endl;
			break;
		}
		else
		{
			cvtColor(frame, rframe, CV_RGB2GRAY);
			//sobel��Ե��ȡ����
			Sobel(rframe, dx, CV_16SC1, 1, 0, 3);
			convertScaleAbs(dx, abs_dx);
			Sobel(rframe, dy, CV_16SC1, 1, 0, 3);
			convertScaleAbs(dy, abs_dy);
			//canny���ӣ�1��
			Canny(dx, dy, Canny1,100 ,300, false);
			imshow("Canny1", Canny1);
			//Canny���ӣ�2��
			Canny(frame, Canny2, 80, 240, 3, false);
			imshow("Canny2", Canny2);
			imshow("frame", frame);
		}
		waitKey(30);

	}
	return 0;



}