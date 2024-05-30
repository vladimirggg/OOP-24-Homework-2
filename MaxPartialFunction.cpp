#include "MaxPartialFunction.h"

void MaxPartialFunction::copyFrom(const MaxPartialFunction& other){
    size = other.size;
    for (size_t i = 0; i < size; i++){
        funcs[i] = other.funcs[i].clone();
    }
}

void MaxPartialFunction::moveFrom(MaxPartialFunction&& other){
    size = other.size;
    other.size = 0;

    for (size_t i = 0; i < size; i++){
        funcs[i] = other.funcs[i];
        other.funcs[i] = nullptr;
    }
}

void MaxPartialFunction::free(){
    for (size_t i = 0; i < size; i++){
        funcs[i] = nullptr;
    }
    size = 0;
}

MaxPartialFunction::MaxPartialFunction(): size(0) {}

MaxPartialFunction::MaxPartialFunction(PartialFunction** _funcs, size_t _size){
    if(size > MAX_SIZE) throw std::runtime_error("Number of arguments exceeds limit!");

    size = _size;
    for (size_t i = 0; i < _size; i++){
        funcs[i] = _funcs[i]->clone();
    }
}

MaxPartialFunction::MaxPartialFunction(const MaxPartialFunction& other){
    copyFrom(other);
}

MaxPartialFunction::MaxPartialFunction(MaxPartialFunction&& other){
    moveFrom(std::move(other));
}

MaxPartialFunction& MaxPartialFunction::operator=(const MaxPartialFunction& other)
{
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

MaxPartialFunction& MaxPartialFunction::operator=(MaxPartialFunction&& other){
    if(this != &other){
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

PartialFunction* MaxPartialFunction::clone() const{
    return new MaxPartialFunction(*this);
}

bool MaxPartialFunction::isDefined(int x) const{
    for (size_t i = 0; i < size; i++){
        if(funcs[i]->isDefined(x)) return true;
    }
    return false;
}

resultPair MaxPartialFunction::operator()(int x) const{
    resultPair max;
    for (size_t i = 0; i < size; i++){
        resultPair temp = funcs[i](x);
        if(temp.second > max.second) max = temp;
    }
    return max;
}

MaxPartialFunction::~MaxPartialFunction(){
    free();
}
