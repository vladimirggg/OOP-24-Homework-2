#include "Criteria2Func.h"

int Criteria2Func::getIndex(int x) const
{
    for(int i = 0; i < size; ++i)
        if(args[i] == x) return i;
    
    return -1;
}

Criteria2Func::Criteria2Func(int* _args, size_t _size){
    if(size > MAX_SIZE) throw std::runtime_error("Number of arguments exceeds limit!");

    size = _size;
    for (size_t i = 0; i < size; i++)
        args[i] = _args[i];
    
}

PartialFunction * Criteria2Func::clone() const{
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