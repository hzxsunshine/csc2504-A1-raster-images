#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  bool blue = true;
  bool red = false;
  bool green = true;
  for(int i=0; i< height;i++){
      for(int j=0;j<width;j++){
          if(blue) {
              if (green) {
                  bayer[i * width + j] = rgb[i * width * 3 + j * 3 + 1];
                  green = false;
              } else {
                  bayer[i * width + j] = rgb[i * width * 3 + j * 3 + 2];
                  green = true;
              }
          }
          else if(red) {
              if (green) {
                  bayer[i * width + j] = rgb[i * width * 3 + j * 3 + 1];
                  green = false;
              } else {
                  bayer[i * width + j] = rgb[i * width * 3 + j * 3];
                  green = true;
              }
          }
      }
      blue = not blue;
      red = not red;
      green = not red;
  }
}
