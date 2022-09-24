# Image-Processing

- please star it if it's useful for you.

## Author

- Shandong University 山东大学
- Class of Artificial Intelligence, 2019 人工智能班
- Young Lee 李阳

## Update Log

- 2022/9/18 initial commit and [exp1](###exp1)
- 2022/9/24 [exp2](###exp2)

## Content

### exp1 [code](https://github.com/Liesy/Image-Processing/blob/main/E1)

- 以下C/C++函数原型用于从多通道图像（交叉存储）中读取任意通道，请完成该函数的实现并基于OpenCV进行测试：
  ```c++
  void getChannel(const unsigned char* input, int width, int height, int inStep, int inChannels, unsigned char* output, int outStep, int channelToGet);
  ```
  > input, width, height, inStep, inChannels 分别是输入图像的数据、宽、高、step和通道数。
  >
  > output和outStep是输出图像的数据和step，宽高与输入图像相同，通道数为1。
  >
  > channelToGet是获取的通道索引，比如channelToGet=0获取BGR中的B通道。
- 现有一张4通道透明图像a.png，从其中提取alpha通道并显示，用alpha混合，为a.png替换一张新背景（背景图自选）。

### exp2 [code](https://github.com/Liesy/Image-Processing/blob/main/E2)

- 设计一个Sigmoid函数，实现对图像的对比度调整，并使得调整幅度可以通过参数控制```使用OpenCV窗口系统的slider控件，交互改变Sigmoid函数的参数，实现不同程度的对比度调整```
- 对图像I和对应的背景图B，基于图像相减检测I中的前景区域，并输出前景的mask，分析误检情况，设法改进。