#include "include/ans_handler.hpp"
#include <iostream>

int main() {
  const double pi = 3.14159265358979323846;
  AnswerHandler handler;
  handler.epsilone = 1E-12;
  std::cout << "Point is PI * N / 2, where N is the number of point.\n";
  std::cout << "4 numbers after point are value of sin, cos, tan, cotan\n";
  for (int i = 0; i < 4; i++) {
    handler.point = pi * i / 2;
    std::cout << "Point: " << i << "\n";
    for (int j = 0; j < 4; j++) {
      handler.point_result = handler.my_trig(j);
      std::cout << "        " << j << ": " << handler.point_result << "\n";
    }
  }
  std::cout << "\n";
  return 0;
}
