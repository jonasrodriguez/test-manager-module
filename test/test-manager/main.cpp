#include <iostream>
#include <memory>

#include "Operations/Calculation.h"
#include "Operations/Calibration.h"
#include "Operations/Quality.h"
#include "Orders/Order.h"
#include "Tests/BiochemistryTest.h"
#include "Tests/HematologyTest.h"
#include "Tests/ImmunologyTest.h"
#include "Tests/MicrobiologyTest.h"

void OrderWithOneTest(const Sample &sample) {
  std::cout << "** OrderWithOneTest **" << std::endl << std::endl;

  // Create order
  Order order(sample);

  // Create bio test
  std::shared_ptr<BiochemistryTest> bio = std::make_shared<BiochemistryTest>();
  bio->SetPropertyA("A");
  bio->SetPropertyB("B");
  bio->SetPropertyBio("Bio");

  // Add calculation to Biochemistry test
  std::shared_ptr<Calculation> calcul = std::make_shared<Calculation>();
  order.AddOperationForTest(bio, calcul);

  // Add calibration to Biochemistry test
  std::shared_ptr<Calibration> cali = std::make_shared<Calibration>();
  order.AddOperationForTest(bio, cali);

  // Run order
  std::cout << "Running order operations!" << std::endl;
  order.RunOperations();

  // Check order results
  std::cout << "Operations "
            << ((order.GetResults()) ? "finished successfully!" : "failed!")
            << std::endl;
}

void OrderWithTwoDifferentTest(const Sample &sample) {
  std::cout << std::endl
            << "** OrderWithTwoDifferentTest **" << std::endl
            << std::endl;

  // Create order
  Order order(sample);

  // Create hemato test
  std::shared_ptr<HematologyTest> hema = std::make_shared<HematologyTest>();
  hema->SetPropertyA("A");
  hema->SetPropertyB("B");
  hema->SetPropertyHema("Hema");

  // Create micro test
  std::shared_ptr<MicrobiologyTest> micro =
      std::make_shared<MicrobiologyTest>();
  micro->SetPropertyA("A2");
  micro->SetPropertyB("B2");
  micro->SetPropertyMicro("Micro");

  // Add calculation to Hematology test
  std::shared_ptr<Calculation> calcul = std::make_shared<Calculation>();
  order.AddOperationForTest(hema, calcul);

  // Add quality control to Hematology test
  std::shared_ptr<Quality> qa = std::make_shared<Quality>();
  order.AddOperationForTest(hema, qa);

  // Add quality control to Microbiology test
  std::shared_ptr<Calibration> calib = std::make_shared<Calibration>();
  order.AddOperationForTest(micro, calib);

  // Run order
  std::cout << "Running order operations:" << std::endl;
  order.RunOperations();

  // Check order results
  std::cout << "Operations "
            << ((order.GetResults()) ? "finished successfully!" : "failed!")
            << std::endl;
}

void OrderWithTwoEqualTest(const Sample &sample) {
  std::cout << std::endl
            << "** OrderWithTwoEqualTest **" << std::endl
            << std::endl;

  // Create order
  Order order(sample);

  // Create hemato test
  std::shared_ptr<ImmunologyTest> immu1 = std::make_shared<ImmunologyTest>();
  immu1->SetPropertyA("A");
  immu1->SetPropertyB("B");
  immu1->SetPropertyImmu("Immu");

  // Create micro test
  std::shared_ptr<ImmunologyTest> immu2 = std::make_shared<ImmunologyTest>();
  immu2->SetPropertyA("A2");
  immu2->SetPropertyB("B2");
  immu2->SetPropertyImmu("Immu2");

  // Add calculation to both Immunology test
  std::shared_ptr<Calculation> calcul = std::make_shared<Calculation>();
  order.AddOperationForTest(immu1, calcul);
  order.AddOperationForTest(immu2, calcul);

  // Add quality control to first Immunology test
  std::shared_ptr<Quality> qa = std::make_shared<Quality>();
  order.AddOperationForTest(immu1, qa);

  // Add quality control to second Immunology test
  std::shared_ptr<Calibration> calib = std::make_shared<Calibration>();
  order.AddOperationForTest(immu2, calib);

  // Run order
  std::cout << "Running order operations:" << std::endl;
  order.RunOperations();

  // Check order results
  std::cout << "Operations "
            << ((order.GetResults()) ? "finished successfully!" : "failed!")
            << std::endl;
}

int main() {
  Sample sample;
  sample.sampleId = 123;
  sample.patientInfo = "Pepe";

  OrderWithOneTest(sample);
  OrderWithTwoDifferentTest(sample);
  OrderWithTwoEqualTest(sample);
}
