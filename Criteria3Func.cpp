#include "Criteria3Func.h"

Criteria3Func::Criteria3Func(int* _args, size_t _size)
    :CriteriaType(_args, _size){}

CriteriaType* Criteria3Func::clone() const{
    return new Criteria3Func(*this);
}

bool Criteria3Func::isDefined(int x) const{
    return true;
}

resultPair Criteria3Func::operator()(int x) const{
    int index = getIndex(x);
    if(index == -1) return {true, 0};
    else return {true, 1};
}