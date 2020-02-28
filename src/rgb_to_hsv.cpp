#include "rgb_to_hsv.h"
#include <algorithm>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double max;
  double min;
  max = std::max({r,g,b});
  min = std::min({r,g,b});
  double delta = max - min;

  // Hue
  if(delta < 0.00001 ){
      h = 0;
  } else if (max == r){
      h = (g - b)/delta;
  } else if (max == g){
      h = (b - r)/delta + 2.0;
  } else if (max == b){
      h = (r - g)/delta + 4.0;
  }
  h *= 60.0;

  // Saturation
  if (max == 0){
      s = 0;
  }
  else{
      s = delta / max;
  }

  // Value
  v = max;

  ////////////////////////////////////////////////////////////////////////////
}
