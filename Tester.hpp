#ifndef TESTER_HPP
#define TESTER_HPP

#include "concreteClassses/strategy/strategyInterface.hpp"
#include <memory>

namespace test{
class Tester{

  public:
    explicit Tester(std::unique_ptr<StrategyInterface> && strategy = {}) : 
      strategy_(std::move(strategy)){}

    // binds a test concrete class, options are for operations are:
    // 
    // Assignment:
    //  AllAssignment
    //  Assignment
    //  MoveAssignment
    //  TrivialAssignment
    //
    // Construction:
    //  AllConstruction
    //  Construction
    //  DefaultConstruction
    //  CopyConstruction
    //  MoveConstruction
    void bindTestType(std::unique_ptr<StrategyInterface> && strategy);

    bool runTest() const;

  private:
    std::unique_ptr<StrategyInterface> strategy_;
};

  void Tester::bindTestType(std::unique_ptr<StrategyInterface> && strategy) {
    strategy_ = std::move(strategy);
  }

  bool Tester::runTest() const {
    return strategy_->testOperations();
  }
}

#endif
