#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  double red = 0;
  double green = 0;
  double blue = 0;
  double hue = 0;
  double saturation = 0;
  double value = 0;
  for (int i=0; i < width * height; i++){
      red = (double)rgb[3 * i] / 255;
      green = (double)rgb[3 * i + 1] / 255;
      blue = (double)rgb[3 * i + 2] / 255;
      rgb_to_hsv(red,green,blue,hue,saturation,value);
      hue += shift;
      hsv_to_rgb(hue,saturation,value,red,green,blue);
      shifted[3 * i] = (unsigned char)(red * 255);
      shifted[3 * i + 1] = (unsigned char)(green * 255);
      shifted[3 * i + 2] = (unsigned char)(blue * 255);
  }
}
