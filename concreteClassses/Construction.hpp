#ifndef TESTHELPER_CONSTRUCTION_HPP
#define TESTHELPER_CONSTRUCTION_HPP

#include "strategy/strategyInterface.hpp"
#include <memory>
#include <type_traits>
#include <iostream>

#define constructible(...) std::is_constructible<__VA_ARGS__>() && std::is_trivially_constructible<__VA_ARGS__>() && std::is_nothrow_constructible<__VA_ARGS__>()

namespace tstHelper{
  
  template <class T, class U = T, class V = U, class W = V, class X = W, class Y = X, class Z = Y >
  class Construction : public StrategyInterface{

    public:
   
    bool testOperations(int numParams) override{
      switch(numParams){
        case 0:
          return std::is_default_constructible<T>() &&
                 std::is_trivially_default_constructible<T>() &&
                 std::is_nothrow_default_constructible<T>();
        case 1:
          return constructible(T, U);
        case 2:
          return constructible(T, U, V);
        case 3:
          return constructible(T, U, V, W);
        case 4:
          return constructible(T, U, V, W, X);
        case 5:
          return constructible(T, U, V, W, X, Y);
        case 6:
          return constructible(T, U, V, W, X, Y, Z);
        default:
          return false;
      }
    }

    private:
      std::unique_ptr<StrategyInterface> strategy_;
  };

  

}

#undef constructible
#endif
