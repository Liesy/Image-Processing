#include "exp1.h"
#include <iostream>

using namespace cv;

uchar* getPixel(const uchar* data, int width, int height, int step, int channels, int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        std::cout << "invalid (x, y)\n";
        return nullptr;
    }
    return (uchar*)data + y * step + x * channels;
}

void getChannel(const uchar* input, int width, int height, int inStep, int inChannels,
    uchar* output, int outStep, int channelToGet) {
    if (channelToGet >= inChannels) {
        std::cout << "invalid value for channelToGet\n";
        return;
    }
    uchar *row_out = output;
    for (int y = 0; y < height; ++y, row_out += outStep) {
        uchar* pix_out = row_out;
        for (int x = 0; x < width; ++x, ++pix_out) {
            //*pix_out = *(input + y * inStep + x * inChannels + channelToGet);
            *pix_out = *(getPixel(input, width, height, inStep, inChannels, x, y) + channelToGet);
        }
    }
}

void alphaBlend(const uchar* input, int width, int height, int inStep, int inChannels,
    const uchar* bg, int bgStep, int bgChannels,
    const uchar* alpha, int aStep,
    uchar* output, int outStep, int outChannels) {
    uchar* row_out = output;
    for (int y = 0; y < height; ++y, row_out += outStep) {
        uchar* pix_out = row_out;
        for (int x = 0; x < width; ++x, pix_out += outChannels) {
            //double tmp = *(alpha + y * aStep + x) / 255.0;
            double tmp = *getPixel(alpha, width, height, aStep, 1, x, y) / 255.0;
            for (int c = 0; c < outChannels; ++c) {
                //*(pix_out + c) = tmp * (*(input + y * inStep + x * inChannels + c)) + (1 - tmp) * (*(bg + y * bgStep + x * bgChannels + c));
                uchar px_fg = *(getPixel(input, width, height, inStep, inChannels, x, y) + c) * tmp;
                uchar px_bg = *(getPixel(bg, width, height, bgStep, bgChannels, x, y) + c) * (1 - tmp);
                *(pix_out + c) = px_fg + px_bg;
            }
        }
    }
}

int main() {
    const std::string img_file = "./E1/a.png";  // change the path.
    const std::string bg_file = "./E1/bg.jpg";  // change the path.
    Mat img = imread(img_file, CV_LOAD_IMAGE_UNCHANGED);
    Mat bg = imread(bg_file, CV_LOAD_IMAGE_COLOR);

    //imshow("img", img);
    //waitKey(0);
    //imshow("bg", bg);
    //waitKey(0);

    int width = img.cols, height = img.rows, channels = img.channels();
    std::cout << "width=" << width << " height=" << height << " channels=" << channels;
    
    Mat img_alpha(height, width, CV_8UC1);
    getChannel(img.data, width, height, img.step, channels, img_alpha.data, img_alpha.step, 3);
    
    imshow("alpha", img_alpha);
    waitKey(0);

    Mat img_blend(height, width, CV_8UC3);
    alphaBlend(img.data, width, height, img.step, img.channels(),
        bg.data, bg.step, bg.channels(),
        img_alpha.data, img_alpha.step,
        img_blend.data, img_blend.step, img_blend.channels());

    imshow("blend", img_blend);
    waitKey(0);

    return 0;
}