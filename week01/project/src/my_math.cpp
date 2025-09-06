#include "../include/my_math.hpp"
#include <cmath>
const double pi = 3.14159265358979323846;

AnswerHandler my_sin(double point, double epsilone) {
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

  AnswerHandler result;
  result.point = point;
  result.epsilone = epsilone;
  result.point_result = s * sign;
  return result;
}

AnswerHandler my_cos(double point, double epsilone) {
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
  AnswerHandler result;
  result.point = point;
  result.epsilone = epsilone;
  result.point_result = s * sign;
  return result;
}

AnswerHandler my_tan(double point, double epsilone) {
  double sin_val = my_sin(point, epsilone).point_result;
  double cos_val = my_cos(point, epsilone).point_result;

  AnswerHandler result;
  result.point = point;
  result.epsilone = epsilone;

  // exeptions
  if (std::fabs(cos_val) < epsilone) {
    if (sin_val > 0) {
      result.point_result = 1.0 / 0.0;
      return result; // +inf
    }
    if (sin_val < 0) {
      result.point_result = -1.0 / 0.0;
      return result; // -inf
    }
    result.point_result = 0.0;
    return result; // 0/0
  }

  result.point_result = sin_val / cos_val;
  return result;
}

AnswerHandler my_cotan(double point, double epsilone) {
  double sin_val = my_sin(point, epsilone).point_result;
  double cos_val = my_cos(point, epsilone).point_result;

  AnswerHandler result;
  result.point = point;
  result.epsilone = epsilone;

  // exeptions
  if (std::fabs(sin_val) < epsilone) {
    if (cos_val > 0) {
      result.point_result = 1.0 / 0.0;
      return result; // +inf
    }
    if (cos_val < 0) {
      result.point_result = -1.0 / 0.0;
      return result; // -inf
    }
    result.point_result = 0.0;
    return result; // 0/0
  }
  result.point_result = cos_val / sin_val;
  return result;
}
