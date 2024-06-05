#include "MinPartialFunction.h"

void MinPartialFunction::copyFrom(const MinPartialFunction& other){
    size = other.size;
    funcs = new PartialFunction*[size];

    for (size_t i = 0; i < size; i++){
        funcs[i] = other.funcs[i]->clone();
    }
}

void MinPartialFunction::moveFrom(MinPartialFunction&& other) noexcept{
    size = other.size;

    funcs = other.funcs;
    other.funcs = nullptr;
}

void MinPartialFunction::free(){
    for (size_t i = 0; i < size; i++){
        delete[] funcs[i];
    }
    delete[] funcs;
    size = 0;
}

MinPartialFunction::MinPartialFunction(): funcs(nullptr), size(0) {}

MinPartialFunction::MinPartialFunction(PartialFunction** _funcs, size_t _size) {
    if(size > MAX_SIZE) throw std::runtime_error("Number of arguments exceeds limit!");

    size = _size;
    funcs = new PartialFunction* [size];
    for (size_t i = 0; i < _size; i++){
        this->funcs[i] = _funcs[i]->clone();
    }
}

MinPartialFunction::MinPartialFunction(const MinPartialFunction& other){
    copyFrom(other);
}

MinPartialFunction::MinPartialFunction(MinPartialFunction&& other) noexcept{
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

MinPartialFunction& MinPartialFunction::operator=(MinPartialFunction&& other) noexcept{
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
        if(!funcs[i]->isDefined(x)) return false;
    }
    return true;
}

int MinPartialFunction::invoke(int x) const{
    int min = INT_MAX;
    for (size_t i = 0; i < size; i++){
        int temp = funcs[i]->invoke(x);// if undefined, throws an exception
        if (temp < min)
            min = temp;
    }
    return min;
}

MinPartialFunction::~MinPartialFunction(){
    free();
}
