#include "hsv_to_rgb.h"
#include <cmath>

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  ////////////////////////////////////////////////////////////////////////////

    float chroma = v * s; // Chroma
    float fHPrime = fmod(h / 60.0, 6);
    float fX = chroma * (1 - fabs(fmod(fHPrime, 2) - 1));
    float fM = v - chroma;

    if(0 <= fHPrime && fHPrime < 1) {
        r = chroma;
        g = fX;
        b = 0;
    } else if(1 <= fHPrime && fHPrime < 2) {
        r = fX;
        g = chroma;
        b = 0;
    } else if(2 <= fHPrime && fHPrime < 3) {
        r = 0;
        g = chroma;
        b = fX;
    } else if(3 <= fHPrime && fHPrime < 4) {
        r = 0;
        g = fX;
        b = chroma;
    } else if(4 <= fHPrime && fHPrime < 5) {
        r = fX;
        g = 0;
        b = chroma;
    } else if(5 <= fHPrime && fHPrime < 6) {
        r = chroma;
        g = 0;
        b = fX;
    } else {
        r = 0;
        g = 0;
        b = 0;
    }

    r += fM;
    g += fM;
    b += fM;
}
