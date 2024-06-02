#include "Criteria3Func.h"

Criteria3Func::Criteria3Func(int* _args, size_t _size)
    :CriteriaType(_args, _size){}

CriteriaType* Criteria3Func::clone() const{
    return new Criteria3Func(*this);
}

bool Criteria3Func::isDefined(int x) const{
    if(getIndex(x) == -1) return false;
    else return true;
}

resultPair Criteria3Func::operator()(int x) const{
    int index = getIndex(x);
    if(index == -1) return {false, 0};
    else return {true, 1};
}