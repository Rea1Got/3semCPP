#ifndef ANS_HANDLER_HPP
#define ANS_HANDLER_HPP

struct AnswerHandler {
  double point;
  double point_result;
  double epsilone = 10E-10;

  double my_trig(unsigned int);
};
#endif
