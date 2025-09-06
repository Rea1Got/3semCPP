#include "../include/ans_handler.hpp"
#include "../include/my_math.hpp"
#include <iostream>

AnswerHandler AnswerHandler::my_trig(unsigned int num_func) {
  switch (num_func) {
  case 0:
    return my_sin(point, epsilone);
  case 1:
    return my_cos(point, epsilone);
  case 2:
    return my_tan(point, epsilone);
  case 3:
    return my_cotan(point, epsilone);
  default:
    std::cout << "Wrong number of function (0-3 needed)";
    AnswerHandler wrong;
    wrong.point = -1337;
    wrong.point_result = -69;
    return wrong;
  }
}
