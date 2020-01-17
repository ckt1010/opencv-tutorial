#include <opencv2/opencv.hpp>

using namespace std;

void smooth(cv::Mat &img) {
    cv::Mat out;
    cv::namedWindow("cktExample1-smooth", cv::WINDOW_AUTOSIZE);
    cv::GaussianBlur(img, out, cv::Size(5, 5), 3, 3);
    cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);
    cv::imshow("cktExample1-smooth", out);
}

void pyrDown(cv::Mat &img) {
    cv::Mat out;
    cv::namedWindow("cktExample1-pyrDown", cv::WINDOW_AUTOSIZE);
    cv::pyrDown(img, out);
    cv::imshow("cktExample1-pyrDown", out);
}

void cvtColor(cv::Mat &img) {
    cv::Mat out_gry, out_cny;
    int x = 16, y = 32;

    cv::Vec3b intensity = img.at<cv::Vec3b>(y, x);
    cout << "RGB: " << (unsigned)intensity[0] << " , " << (unsigned)intensity[1] << " , " << (unsigned)intensity[2] << endl;
    cv::namedWindow("cktExample1-gray", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("cktExample1-canny", cv::WINDOW_AUTOSIZE);
    cv::cvtColor(img, out_gry, cv::COLOR_BGR2GRAY);
    cv::Canny(out_gry, out_cny, 10, 100, 3, true);
    cout << "GRAY: " << (unsigned)out_gry.at<uchar>(y, x) << endl;
    out_cny.at<uchar>(x, y) = 128;
    cv::imshow("cktExample1-gray", out_gry);
    cv::imshow("cktExample1-canny", out_cny);
}

int main(int argc, char **argv) {
    cv::Mat img = cv::imread(argv[1], -1);
    if (img.empty()) {
        return -1;
    }
    cv::namedWindow("cktExample1", cv::WINDOW_AUTOSIZE);
    cv::imshow("cktExample11", img);
    smooth(img);
    pyrDown(img);
    cvtColor(img);
    cv::waitKey(0);
    cv::destroyWindow("cktExample1");
}