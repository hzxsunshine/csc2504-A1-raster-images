#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for(int i = 0; i < height; i++){
      for(int j= 0; j<width;j++){
            rotated[(width - j - 1) * height * 3 + i * 3] = input[i * width * 3 + j * 3];
            rotated[(width - j - 1) * height * 3 + i * 3 + 1] = input[i * width * 3 + j * 3 + 1];
            rotated[(width - j - 1) * height * 3 + i * 3 + 2] = input[i * width * 3 + j * 3 + 2];

            // for clockwise
//          rotated[i * height * 3 + j * 3] = input[j * width * 3 + i * 3];
//          rotated[i * height * 3 + j * 3 + 1] = input[j * width * 3 + i * 3 + 1];
//          rotated[i * height * 3 + j * 3 + 2] = input[j * width * 3 + i * 3 + 2];
      }
  }
}
