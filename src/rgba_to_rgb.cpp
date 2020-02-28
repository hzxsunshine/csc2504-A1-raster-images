#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  int count = 0;
  // vector might have some property that can move this indexes directly? (j mod 4 = 3)
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for(int i =0; i< height * width * 4; i++){
      if ((i+1)%4 != 0){
              rgb.at(count) = rgba[i];
              count += 1;
          }
  }
  ////////////////////////////////////////////////////////////////////////////
}
