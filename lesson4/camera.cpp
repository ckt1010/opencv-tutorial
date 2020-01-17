#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char **argv) {
    cv::namedWindow("lesson4_bgr", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("lesson4_logpolar", cv::WINDOW_AUTOSIZE);
    cv::Mat logpolar_frame, bgr_frame;
    cv::VideoCapture cap;
    if (argc == 1) {
        cap.open(0);
    } else {
        cap.open(argv[1]);
    }
    if (!cap.isOpened()) {
        cerr << "Couldn't open capture\n";
        return -1;
    }
    double fr = cap.get(cv::CAP_PROP_FPS);
    int tmpw = (int)cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph = (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    cv::Size size((int)tmpw, tmph);
    cout << "fr: " << fr << endl;

    cv::VideoWriter writer;
    writer.open(argv[2], cv::VideoWriter::fourcc('M','P','4','V'), fr, size);
    while (1) {
        cap >> bgr_frame;
        if (bgr_frame.empty()) {
            break;
        }
        cv::imshow("lesson4_bgr", bgr_frame);
        cv::waitKey(1000 / fr);
        cv::logPolar(bgr_frame, logpolar_frame,
                     cv::Point2f(bgr_frame.cols / 2, bgr_frame.rows / 2), 40,
                     cv::WARP_FILL_OUTLIERS);
        cv::imshow("lesson4_logpolar", logpolar_frame);
        writer << logpolar_frame;

        cv::waitKey(1000 / fr);
    }

    cv::destroyWindow("lesson4_bgr");
    cv::destroyWindow("lesson4_logpolar");
}