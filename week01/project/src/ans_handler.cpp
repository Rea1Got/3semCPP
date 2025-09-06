#include "../include/ans_handler.hpp"
#include "../include/my_math.hpp"
#include <iostream>

double AnswerHandler::my_trig(unsigned int num_func) {
  switch (num_func) {
  case 0:
    return point_result = my_sin(point, epsilone);
  case 1:
    return point_result = my_cos(point, epsilone);
  case 2:
    return point_result = my_tan(point, epsilone);
  case 3:
    return point_result = my_cotan(point, epsilone);
  default:
    std::cout << "Wrong number of function (0-3 needed)";
    return -1;
  }
}
