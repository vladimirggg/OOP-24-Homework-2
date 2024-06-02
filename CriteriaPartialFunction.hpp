#pragma once
#include "PartialFunction.h"
#include "CriteriaType.h"
#include <iostream>

template <class Function>
class CriteriaPartialFunction : public PartialFunction{
    Function func;
public:
    CriteriaPartialFunction(resultPair(*_func)(int));
    explicit CriteriaPartialFunction(const Function& _func);
    PartialFunction* clone() const override;
    bool isDefined(int x) const override;
    int invoke(int x) const override;
    ~CriteriaPartialFunction() = default;
};

template<class Function>
CriteriaPartialFunction<Function>::CriteriaPartialFunction(resultPair(*_func)(int)): func(_func){}

template <class Function>
CriteriaPartialFunction<Function>::CriteriaPartialFunction(const Function& _func) : func(_func){}

template<class Function>
inline PartialFunction* CriteriaPartialFunction<Function>::clone() const{
    return new CriteriaPartialFunction(*this);
}

template <class Function>
bool CriteriaPartialFunction<Function>::isDefined(int x) const{
    return func(x).first;
}

template <class Function>
int CriteriaPartialFunction<Function>::invoke(int x) const{
    resultPair result = func(x);
    return result.first ? result.second : throw std::invalid_argument("Undefined argument!");
}