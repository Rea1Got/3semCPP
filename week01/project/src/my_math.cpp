#include "../include/my_math.hpp"
#include <cmath>
const double pi = 3.14159265358979323846;

double my_sin(double point, double epsilone) {
  int sign = (point < 0) ? -1 : 1;
  // [0, 2*pi]
  point = fmod(std::fabs(point), 2 * pi);
  // [0, pi]
  if (point > pi) {
    point -= pi;
    sign *= -1;
  }
  // [0, pi/2]
  if (point > pi / 2)
    point = pi - point;

  double t = point, s = point;
  for (int n = 3; std::fabs(t) > epsilone; n += 2)
    s += t = -t * point * point / n / (n - 1);
  return s * sign;
}

double my_cos(double point, double epsilone) {
  int sign = 1;
  point = std::fabs(point);

  // [0, 2*pi]
  point = std::fmod(point, 2 * pi);

  // symmetry
  if (point > pi) {
    point = 2 * pi - point;
  }

  // sign change
  if (point > pi / 2) {
    point = pi - point;
    sign = -1;
  }

  double s = 1.0; // 1st
  double t = 1.0; // 2nd
  for (int n = 2; std::fabs(t) > epsilone; n += 2) {
    t = -t * point * point / (n * (n - 1));
    s += t;
  }

  return sign * s;
}

double my_tan(double point, double epsilone) {
  double sin_val = my_sin(point, epsilone);
  double cos_val = my_cos(point, epsilone);

  // exeptions
  if (std::fabs(cos_val) < epsilone) {
    if (sin_val > 0)
      return 1.0 / 0.0; // +inf
    if (sin_val < 0)
      return -1.0 / 0.0; // -inf
    return 0.0;          // 0/0
  }

  return sin_val / cos_val;
}

double my_cotan(double point, double epsilone) {
  double sin_val = my_sin(point, epsilone);
  double cos_val = my_cos(point, epsilone);

  // exeptions
  if (std::fabs(sin_val) < epsilone) {
    if (cos_val > 0)
      return 1.0 / 0.0; // +inf
    if (cos_val < 0)
      return -1.0 / 0.0; // -inf
    return 0.0;          // 0/0
  }

  return cos_val / sin_val;
}
