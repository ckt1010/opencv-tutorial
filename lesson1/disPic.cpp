#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
    cv::Mat img = cv::imread(argv[1], -1);
    if (img.empty())
    {
        return -1;
    }
    // cv::namedWindow("cktExample1", cv::WINDOW_AUTOSIZE);
    cv::imshow("cktExample11", img);
    cv::waitKey(0);
    cv::destroyWindow("cktExample1");
}