#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int g_slider_position = 0;
int g_run = 1, g_dontset = 0;
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *) {
    cout << __FUNCTION__ << endl;
    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    if (!g_dontset)
    {
        g_run = 1;
    }
    g_dontset = 0;
}

int main(int argc, char** argv) {
    cv::namedWindow("lesson3", cv::WINDOW_AUTOSIZE);
    g_cap.open(std::string(argv[1]));
    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    cout << "Video has " << frames << " frames of dimensions(" << tmpw << "x" << tmph << ")" << endl;

    cv::createTrackbar("Position", "lesson3", &g_slider_position, frames, onTrackbarSlide);
    cv::Mat frame;
    while (1)
    {
        if (g_run != 0)
        {
            g_cap >> frame;
            if (frame.empty())
            {
                break;
            }
            int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
            g_dontset = 1;

            cv::setTrackbarPos("Position", "lesson3", current_pos);
            cv::imshow("lesson3", frame);

            g_run -= 1;
        }
        
        switch ((char) cv::waitKey(10))
        {
        case 's':
            g_run = 1;
            cout << "Single step, run = " << g_run << endl;
            break;
        case 'r':
            g_run = -1;
            cout << "Run mode, run = " << g_run << endl;
            break;
        case 'x':
            return 0;
        }
    }
    return 0;
}