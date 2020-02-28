#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  if (num_channels == 3) {
      for(int i = 0; i <height; i ++){
          for(int j=0; j < width; j++){
              reflected[i*width * 3 + j * 3] = input[(i+1) * width * 3 -  (j+1)*3];
              reflected[i*width * 3 + j * 3 + 1] = input[(i+1) * width * 3 -  (j+1)*3 + 1];
              reflected[i*width * 3 + j * 3 + 2] = input[(i+1) * width * 3 -  (j+1)*3 + 2];
          }
      }
  }
  else {
      for(int i = 0; i <height; i ++){
          for(int j=0; j < width; j++){
              reflected[i * width + j] = input[(i + 1) * width -  (j + 1)];
          }
      }
  }
}
