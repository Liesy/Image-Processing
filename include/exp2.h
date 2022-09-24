#ifndef IMAGEPROCESSING_EXP2_H
#define IMAGEPROCESSING_EXP2_H

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

uchar sigmoid(const float value, float weight);

void contrastAdjust(uchar* data, int width, int height, int step, int channels, uchar (*func)(const float, float));

void bgSubstract(const uchar* data, const uchar* bg_data,
	int width, int height, int step, int channels,
	int threshold,
	uchar* output, int outStep);

#endif //IMAGEPROCESSING_EXP2_H
