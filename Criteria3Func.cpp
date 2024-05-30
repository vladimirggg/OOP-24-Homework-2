#include "Criteria3Func.h"

int Criteria3Func::getIndex(int x) const
{
    for(int i = 0; i < size; ++i)
        if(args[i] == x) return i;
    
    return -1;
}

Criteria3Func::Criteria3Func(int* _args, size_t _size){
    if(size > MAX_SIZE) throw std::runtime_error("Number of arguments exceeds limit!");

    size = _size;
    for (size_t i = 0; i < size; i++)
        args[i] = _args[i];
    
}

PartialFunction* Criteria3Func::clone() const{
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