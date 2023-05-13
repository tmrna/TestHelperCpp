#ifndef TRAITCTDT_HPP
#define TRAITCTDT_HPP

#include <type_traits>
#include <iostream>
#include <ostream>
#include <functional>
#include <string>
#include <vector>

namespace tstHelper{

  template <typename T, typename...Args>
  class TraitCtorDtorOstr{
  
    public:

    TraitCtorDtorOstr(std::ostream& out = std::cout) : out_(out){};
    ~TraitCtorDtorOstr(){};
    void checkOperations();
    
    void bindDest(std::ostream&);

    private:
    std::string traitPass_(const bool & traitPass);
    
    void appendTestResult_(const std::string& title, std::function<bool()> funct);

    std::ostream& out_;

    struct NameAndTest_{
      std::string name;
      std::function<bool()> test;
    };
  };
  
  template <typename T, typename...Args>
  std::string TraitCtorDtorOstr<T, Args...>::traitPass_(const bool & traitPass){
    return traitPass ? "yes" : "no";
  }

  template <typename T, typename...Args>
  void TraitCtorDtorOstr<T, Args...>::appendTestResult_(const std::string& title, std::function<bool()> funct){
    out_ << title << ": " << traitPass_(funct()) << std::endl;
  }

  template <typename T, typename...Args>
  void TraitCtorDtorOstr<T, Args...>::checkOperations(){
    out_ << std::endl;

    const std::vector<NameAndTest_> Tests = {
      {"Constructible", std::is_constructible<T, Args...>()},
      {"Trivially Constructible", std::is_trivially_constructible<T, Args...>()},
      {"Nothrow Constructible", std::is_nothrow_constructible<T, Args...>()},
      {"Default Constructible", std::is_default_constructible<T>()},
      {"Trivially Default Constructible", std::is_trivially_default_constructible<T>()},
      {"Nothrow Default Constructible", std::is_nothrow_default_constructible<T>()},
      {"Copy Constructible", std::is_copy_constructible<T>()},
      {"Trivially Copy Constructible", std::is_trivially_copy_constructible<T>()},
      {"Nothrow Copy Constructible", std::is_nothrow_copy_constructible<T>()},
      {"Move Constructible", std::is_move_constructible<T>()},
      {"Trivially Move Constructible", std::is_trivially_move_constructible<T>()},
      {"Nothrow Move Constructible", std::is_nothrow_move_constructible<T>()},
    };

    for(NameAndTest_ test : Tests){
      appendTestResult_(test.name, test.test);
    }
  }
}

#endif
