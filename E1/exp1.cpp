#include "exp1.h"
#include <iostream>

using namespace cv;

void getChannel(const unsigned char *input, int width, int height, int inStep, int inChannels,
                unsigned char *output, int outStep, int channelToGet) {
    if (channelToGet >= inChannels) {
        std::cout << "invalid value for channelToGet\n";
        return;
    }
    unsigned char *row_out = output;
    for (int y = 0; y < height; ++y, row_out += outStep) {
        unsigned char *pix_out = row_out;
        for (int x = 0; x < width; ++x, ++pix_out) {
            pix_out = (unsigned char *) input + y * inStep + x * inChannels + channelToGet;
        }
    }
}

int main() {
    const std::string img_file = "a.png";
    Mat img = imread(img_file);

    int width = img.cols, height = img.rows, channels = 4;
    Mat img_alpha(height, width, CV_8UC1);
}