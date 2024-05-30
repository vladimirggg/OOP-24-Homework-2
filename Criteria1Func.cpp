#include "Criteria1Func.h"

int Criteria1Func::getIndex(int x) const
{
    for(int i = 0; i < size; ++i)
        if(args[i] == x) return i;
    
    return -1;
}

Criteria1Func::Criteria1Func(int* _args, int* _results, size_t _size){
    if(size > MAX_SIZE) throw std::runtime_error("Number of arguments exceeds limit!");

    size = _size;
    for (size_t i = 0; i < size; i++){
        args[i] = _args[i];
        results[i] = _results[i];
    }
}

PartialFunction* Criteria1Func::clone() const
{
    return new Criteria1Func(*this);
}

bool Criteria1Func::isDefined(int x) const{
    if(getIndex(x) == -1) return false;
    else return true;
}

resultPair Criteria1Func::operator()(int x) const{
    int index = getIndex(x);
    if(index == -1) return {false, 0};
    else return {true, results[index]};
}
