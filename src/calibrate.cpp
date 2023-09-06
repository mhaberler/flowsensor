#include "defs.h"
#include <vector>

// see regression/mVtopressure.py
std::vector<float> r4 = {11.961173923232366, -0.05375597714049206,
                         7.735359692915754e-05, -3.875324102151733e-08,
                         6.9398138249724735e-12};

float polynomial_approx(const std::vector<float> &coef, const float &x) {
  float y = 0.0;
  float xp = 1.0;
  for (size_t j = 0; j < coef.size(); j++) {
    y += coef[j] * xp;
    xp *= x;
  }
  return y;
}

float mVtoPressure(const float &mV) { return polynomial_approx(r4, mV); }