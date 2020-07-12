#include "HematologyTest.h"

#include <iostream>
#include <string>

HematologyTest::HematologyTest() {
  std::cout << "New Hematology test created" << std::endl;
};
HematologyTest::~HematologyTest() {}

bool HematologyTest::accept(Operation *op) const { return op->visit(this); }

std::string HematologyTest::GetPropertyA() const { return m_propA; }
std::string HematologyTest::GetPropertyB() const { return m_propB; }
std::string HematologyTest::GetPropertyHema() const { return m_propHema; }

void HematologyTest::SetPropertyA(const std::string &propA) { m_propA = propA; }

void HematologyTest::SetPropertyB(const std::string &propB) { m_propB = propB; }

void HematologyTest::SetPropertyHema(const std::string &propHema) {
  m_propHema = propHema;
}
