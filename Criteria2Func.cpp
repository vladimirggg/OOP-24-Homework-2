#include "Criteria2Func.h"

Criteria2Func::Criteria2Func(int* _args, size_t _size)
    : CriteriaType(_args, _size){}

CriteriaType * Criteria2Func::clone() const{
    return new Criteria2Func(*this);
}

bool Criteria2Func::isDefined(int x) const{
    if(getIndex(x) == -1) return true;
    else return false;
}

resultPair Criteria2Func::operator()(int x) const{
    int index = getIndex(x);
    if(index == -1) return {true, x};
    else return {false, 0};
}