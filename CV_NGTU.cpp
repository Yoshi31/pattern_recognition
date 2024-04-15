#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("C:/Users/zayka/Source/Repos/CV_NGTU/img.jpg", IMREAD_COLOR);
    if (img.empty()) {
        cout << "Unable to read the image \n" << endl;
        return -1;
    }

    namedWindow("Original", WINDOW_NORMAL);
    imshow("Original", img);

    vector<pair<string, int>> colorConversions = {
        {"GRAY", COLOR_BGR2GRAY},
        {"CIE XYZ", COLOR_BGR2XYZ},
        {"YCC", COLOR_BGR2YCrCb},
        {"HSV", COLOR_BGR2HSV},
        {"CIE Lab", COLOR_BGR2Lab},
        {"CIE Luv", COLOR_BGR2Luv},
        {"HLS", COLOR_BGR2HLS},
        {"YUV", COLOR_BGR2YUV}
    };

    for (const auto& conversion : colorConversions) {
        Mat convertedImg;
        cvtColor(img, convertedImg, conversion.second);
        namedWindow(conversion.first, WINDOW_NORMAL);
        imshow(conversion.first, convertedImg);
    }

    waitKey(0);
    return 0;
}
