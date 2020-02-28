#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  double t_a;
  double t_b;
  double a0;

// formula is from https://en.wikipedia.org/wiki/Alpha_compositing
  for(int i = 0; i < width * height; i ++){
    t_a = (double)A[4 * i + 3] / 255;
    t_b = (double)B[4 * i + 3] / 255;
    a0 = 1 - (1 - t_a) * (1 - t_b);
    C[4 * i] = (unsigned char)((t_a * (double)A[4 * i] + t_b * (1 - t_a) * (double)B[4 * i]) / a0);
    C[4 * i + 1] = (unsigned char)((t_a * (double)A[4 * i + 1] + t_b * (1 - t_a) * (double)B[4 * i + 1]) / a0);
    C[4 * i + 2] = (unsigned char)((t_a * (double)A[4 * i + 2] + t_b * (1 - t_a) * (double)B[4 * i + 2]) / a0);
    C[4 * i + 3] = (unsigned char)a0 * 255;
  }
}
