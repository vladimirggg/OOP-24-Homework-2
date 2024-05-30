#include "MinPartialFunction.h"

void MinPartialFunction::copyFrom(const MinPartialFunction& other){
    size = other.size;
    for (size_t i = 0; i < size; i++){
        funcs[i] = other.funcs[i].clone();
    }
}

void MinPartialFunction::moveFrom(MinPartialFunction&& other){
    size = other.size;
    other.size = 0;

    for (size_t i = 0; i < size; i++){
        funcs[i] = other.funcs[i];
        other.funcs[i] = nullptr;
    }
}

void MinPartialFunction::free(){
    for (size_t i = 0; i < size; i++){
        funcs[i] = nullptr;
    }
    size = 0;
}

MinPartialFunction::MinPartialFunction(): size(0) {}

MinPartialFunction::MinPartialFunction(PartialFunction** _funcs, size_t _size){
    if(size > MAX_SIZE) throw std::runtime_error("Number of arguments exceeds limit!");

    size = _size;
    for (size_t i = 0; i < _size; i++){
        funcs[i] = _funcs[i]->clone();
    }
}

MinPartialFunction::MinPartialFunction(const MinPartialFunction& other){
    copyFrom(other);
}

MinPartialFunction::MinPartialFunction(MinPartialFunction&& other){
    moveFrom(std::move(other));
}

MinPartialFunction& MinPartialFunction::operator=(const MinPartialFunction& other)
{
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

MinPartialFunction& MinPartialFunction::operator=(MinPartialFunction&& other){
    if(this != &other){
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

PartialFunction* MinPartialFunction::clone() const{
    return new MinPartialFunction(*this);
}

bool MinPartialFunction::isDefined(int x) const{
    for (size_t i = 0; i < size; i++){
        if(funcs[i]->isDefined(x)) return true;
    }
    return false;
}

resultPair MinPartialFunction::operator()(int x) const{
    resultPair max;
    for (size_t i = 0; i < size; i++){
        resultPair temp = funcs[i](x);
        if(temp.second < max.second) max = temp;
    }
    return max;
}

MinPartialFunction::~MinPartialFunction(){
    free();
}
