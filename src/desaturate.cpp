#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
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
        saturation *= (1 - factor);
        hsv_to_rgb(hue,saturation,value,red,green,blue);
        desaturated[3 * i] = (unsigned char)(red * 255);
        desaturated[3 * i + 1] = (unsigned char)(green * 255);
        desaturated[3 * i + 2] = (unsigned char)(blue * 255);
    }
}
