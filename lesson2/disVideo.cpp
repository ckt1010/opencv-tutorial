#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int argc, char** argv) {
    cv::namedWindow("lesson2", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    cap.open(std::string(argv[1]));

    cv::Mat frame;
    while (1)
    {
        cap >> frame;
        if (frame.empty())
        {
            break;
        }
        cv::imshow("lesson2", frame);
        if(cv::waitKey(33) >= 0) break;
    }
    return 0;
}