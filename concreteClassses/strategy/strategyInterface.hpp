#ifndef STRATEGYINTERFACE_HPP
#define STRATEGYINTERFACE_HPP

namespace tstHelper{
class StrategyInterface{
  public:
    virtual ~StrategyInterface() = default;

    virtual bool testOperations(int numParams) = 0;
};
}
#endif
