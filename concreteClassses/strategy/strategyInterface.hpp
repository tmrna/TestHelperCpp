#ifndef STRATEGYINTERFACE_HPP
#define STRATEGYINTERFACE_HPP

namespace test{
class StrategyInterface{
  public:
    virtual ~StrategyInterface() = default;

    virtual bool testOperations() = 0;
};
}
#endif
