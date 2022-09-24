#include "exp1.h"
#include "exp2.h"
#include <iostream>

using namespace cv;

uchar sigmoid(const float value, float weight) {
	float v = (float)value * weight;
	return saturate_cast<uchar> (1.0f / (1.0f + exp(-v)));
}

void contrastAdjust(uchar* data, int width, int height, int step, int channels, uchar(*func)(const float v, float w)) {
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			for (int c = 0; c < channels; ++c) {
				uchar* p = getPixel(data, width, height, step, channels, x, y) + c;
				float p_norm = (*p - 127.0) / 255;
				std::cout << "before=" << *p;
				*p = saturate_cast<uchar> (func(p_norm, 10));
				std::cout << " after=" << *p;
			}
		}
	}
}

void bgSubstract(const uchar* data, const uchar* bg_data,
	int width, int height, int step, int channels,
	int threshold,
	uchar* output, int outStep) {
	
	auto isFg = [&channels, &threshold](uchar* pix, uchar* pix_bg) -> bool {
		float d = 0.0f;
		for (int c = 0; c < channels; ++c) d += pow(*(pix + c) - *(pix_bg + c), 2);
		return d >= threshold;
	};

	uchar* p_img = nullptr, * p_bg = nullptr, * p_out = nullptr;

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			p_img = getPixel(data, width, height, step, channels, x, y);
			p_bg = getPixel(bg_data, width, height, step, channels, x, y);
			p_out = getPixel(output, width, height, outStep, 1, x, y);

			*p_out = isFg(p_img, p_bg) ? 255 : 0;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);

	std::string f_img = "./E2/01.jpg";  // change the path.
	std::string f_bg = "./E2/01_bg.jpg";  // change the path.

	Mat img = imread(f_img, CV_LOAD_IMAGE_COLOR);
	int width = img.cols, height = img.rows, channels = img.channels();
	imshow("original", img);
	waitKey(0);

	contrastAdjust(img.data, width, height, img.step, channels, sigmoid);
	imshow("contrast adjust", img);
	waitKey(0);

	Mat img_bg = imread(f_bg, CV_LOAD_IMAGE_COLOR);
	imshow("background", img_bg);
	waitKey(0);

	Mat mask(height, width, CV_8UC1);
	bgSubstract(img.data, img_bg.data, width, height, img.step, channels, 100, mask.data);
	imshow("fg mask", mask);
	waitKey(0);

	return 0;
}