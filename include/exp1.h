#ifndef IMAGEPROCESSING_EXP1_H
#define IMAGEPROCESSING_EXP1_H

#include <opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>

void getChannel(const unsigned char *input, int width, int height, int inStep, int inChannels,
                unsigned char *output, int outStep, int channelToGet);

#endif //IMAGEPROCESSING_EXP1_H
