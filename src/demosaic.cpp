#include "demosaic.h"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
    std::vector<std::vector<unsigned char> > matrix(height, std::vector<unsigned char>(width));
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = bayer[i * width + j];
        }
    }
    bool blue = true;
    bool red = false;
    bool green = true;
    for(int i=0; i< height;i++){
        for(int j=0;j<width;j++){
            if(blue) {
                if (green) {
                    rgb[3 * width * i + 3 * j + 1] = matrix[i][j];
                    //
                    if(i==0){
                        //red
                        rgb[3 * width * i + 3 * j] = matrix[i + 1][j];
                    }else if(i == height - 1){
                        rgb[3 * width * i + 3 * j] = matrix[i - 1][j];
                    }else{
                        rgb[3 * width * i + 3 * j] = (unsigned char)(((double)matrix[i - 1][j] + (double)matrix[i + 1][j])/2);
                    }

                    if(j==0){
                        //blue
                        rgb[3 * width * i + 3 * j + 2] = matrix[i][j + 1];
                    }else if(j == width - 1){
                        rgb[3 * width * i + 3 * j + 2] = matrix[i][j - 1];
                    }else{
                        rgb[3 * width * i + 3 * j + 2] = (unsigned char)(((double)matrix[i][j + 1] + (double)matrix[i][j - 1]) / 2);
                    }
                    green = false;

                } else {
                    //blue
                    rgb[3 * width * i + 3 * j + 2] = matrix[i][j];

                    //red
                    if(j != width - 1 && i == 0){
                        //r
                        rgb[3 * width * i + 3 * j] = (unsigned char)(((double)matrix[i + 1][j + 1] + (double)matrix[i + 1][j - 1]) / 2);
                        //g
                        rgb[3 * width * i + 3 * j + 1] = (unsigned char)(((double)matrix[i][j + 1] + (double)matrix[i][j - 1]
                                                        + (double)matrix[i + 1][j]) / 3);
                    }else if (j == width - 1 && i == 0){
                        rgb[3 * width * i + 3 * j] = (unsigned char)matrix[i + 1][j - 1];
                        //g
                        rgb[3 * width * i + 3 * j + 1] = (unsigned char)(((double)matrix[i][j - 1] + (double)matrix[i + 1][j]) / 2);
                    }else if (i == height - 1 && j != width - 1){
                        //r
                        rgb[3 * width * i + 3 * j] = (unsigned char)(((double)matrix[i - 1][j + 1] + (double)matrix[i - 1][j - 1]) / 2);
                        //g
                        rgb[3 * width * i + 3 * j + 1] = (unsigned char)(((double)matrix[i][j + 1] + (double)matrix[i][j - 1]
                                                                          + (double)matrix[i - 1][j]) / 3);
                    }else if (i == height - 1 && j == width - 1){
                        rgb[3 * width * i + 3 * j] = (unsigned char)matrix[i - 1][j - 1];
                        //green
                        rgb[3 * width * i + 3 * j + 1] = (unsigned char)(( (double)matrix[i][j - 1] + (double)matrix[i - 1][j]) / 3);
                    }else{
                        rgb[3 * width * i + 3 * j] = (unsigned char)(((double)matrix[i + 1][j + 1] + (double)matrix[i + 1][j - 1]
                                + (double)matrix[i - 1][j + 1] + (double)matrix[i - 1][j - 1]) / 4);
                        // green
                        rgb[3 * width * i + 3 * j + 1] = (unsigned char)(((double)matrix[i][j + 1] + (double)matrix[i][j - 1]
                                                                          + (double)matrix[i - 1][j] + (double)matrix[i + 1][j]) / 4);
                    }
                    green = true;
                }
            }
            else if(red) {
                if (green) {
                    //green
                    rgb[3 * width * i + 3 * j + 1] = matrix[i][j];

                    //red
                    if(j == width - 1){
                        rgb[3 * width * i + 3 * j] = matrix[i][j - 1];
                    }else{
                        rgb[3 * width * i + 3 * j] = (unsigned char)(((double)matrix[i][j + 1] + (double)matrix[i][j - 1]) / 2);
                    }

                    //blue
                    if(i == height - 1){
                        rgb[3 * width * i + 3 * j + 2] = matrix[i + 1][j];
                    }else{
                        rgb[3 * width * i + 3 * j + 2] = (unsigned char)(((double)matrix[i + 1][j] + (double)matrix[i - 1][j]) / 2);
                    }


                    green = false;
                } else {
                    //red
                    rgb[3 * width * i + 3 * j] = matrix[i][j];

                    //green
                    if(i == height - 1 && j == width - 1){
                        rgb[3 * width * i + 3 * j + 1] = (unsigned char)(( (double)matrix[i][j - 1]
                                                                      + (double)matrix[i - 1][j]) / 2);
                        //blue
                        rgb[3 * width * i + 3 * j + 2] = matrix[i - 1][j - 1];

                    }else if(i < height - 1 && j == width - 1){
                        rgb[3 * width * i + 3 * j + 1] = (unsigned char)(( (double)matrix[i][j - 1]
                                                                      + (double)matrix[i - 1][j] + (double)matrix[i + 1][j]) / 3);

                        //blue
                        rgb[3 * width * i + 3 * j + 2] = (unsigned char)(( (double)matrix[i - 1][j - 1]
                                                                           + (double)matrix[i + 1][j - 1]) / 2);
                    }else if (i == height - 1 && j < width - 1 && j > 0){
                        rgb[3 * width * i + 3 * j + 1] = (unsigned char)(( (double)matrix[i][j - 1]
                                                                       + (double)matrix[i - 1][j] + (double)matrix[i][j + 1]) / 3);
                        //blue
                        rgb[3 * width * i + 3 * j + 2] = (unsigned char)(( (double)matrix[i - 1][j - 1]
                                                                           + (double)matrix[i - 1][j + 1]) / 2);
                    }else if (i == height - 1 && j == 0){
                    rgb[3 * width * i + 3 * j + 1] = (unsigned char)(((double)matrix[i - 1][j] + (double)matrix[i][j + 1]) / 2);
                    //blue
                    rgb[3 * width * i + 3 * j + 2] = matrix[i - 1][j + 1];

                    }else if(i != height - 1 && j == 0){
                        rgb[3 * width * i + 3 * j + 1] = (unsigned char)(((double)matrix[i][j + 1]+ (double)matrix[i - 1][j] +
                                (double)matrix[i + 1][j]) / 3);

                        //blue
                        rgb[3 * width * i + 3 * j + 2] = (unsigned char)(((double)matrix[i + 1][j + 1] + (double)matrix[i - 1][j + 1]) / 2);
                    }else{
                        rgb[3 * width * i + 3 * j + 1] = (unsigned char)(((double)matrix[i][j + 1] + (double)matrix[i][j - 1]
                                                                          + (double)matrix[i - 1][j] + (double)matrix[i + 1][j]) / 4);

                        //blue
                        rgb[3 * width * i + 3 * j + 2] = (unsigned char)(((double)matrix[i + 1][j + 1] + (double)matrix[i - 1][j - 1]
                                                                      + (double)matrix[i - 1][j + 1] + (double)matrix[i + 1][j - 1]) / 4);
                    }

                    green = true;
                }
            }
        }
        blue = not blue;
        red = not red;
        green = not red;
    }


}
