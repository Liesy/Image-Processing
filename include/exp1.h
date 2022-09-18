#ifndef IMAGEPROCESSING_EXP1_H
#define IMAGEPROCESSING_EXP1_H

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

void getChannel(const uchar* input, int width, int height, int inStep, int inChannels,
    uchar* output, int outStep, int channelToGet);

void alphaBlend(const uchar* input, int width, int height, int inStep, int inChannels,
    const uchar* bg, int bgStep, int bgChannels,
    const uchar* alpha, int aStep,
    uchar* output, int outStep, int outChannels);

#endif //IMAGEPROCESSING_EXP1_H
