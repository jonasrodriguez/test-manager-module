#include "Test.h"

class Biochemistry : public Test {
 public:
  Biochemistry();

 private:
  TestType m_type;
  int m_specificPropD;
  int m_specificPropE;
};
