#ifndef TESTER_HPP
#define TESTER_HPP

#include "concreteClassses/strategy/strategyInterface.hpp"
#include <memory>

namespace tstHelper{

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
      //  CopyConstruction
      //  MoveConstruction
      void bindTestType(std::unique_ptr<StrategyInterface> && strategy);
  
      bool runTest(int argCt) const;
  
    private:
      std::unique_ptr<StrategyInterface> strategy_;
  };


  void Tester::bindTestType(std::unique_ptr<StrategyInterface> && strategy) {
    strategy_ = std::move(strategy);
  }

  bool Tester::runTest(int argCt) const {
    return strategy_->testOperations(argCt);
  }
}

#endif
