#include "MaxPartialFunction.h"

void MaxPartialFunction::copyFrom(const MaxPartialFunction& other){
    size = other.size;
    funcs = new PartialFunction*[size];

    for (size_t i = 0; i < size; i++){
        funcs[i] = other.funcs[i]->clone();
    }
}

void MaxPartialFunction::moveFrom(MaxPartialFunction&& other) noexcept{
    size = other.size;
//    other.size = 0;

    funcs = other.funcs;
    other.funcs = nullptr;
}

void MaxPartialFunction::free(){
    for (size_t i = 0; i < size; i++){
        delete[] funcs[i];
    }
    delete[] funcs;
    size = 0;
}

MaxPartialFunction::MaxPartialFunction(): funcs(nullptr), size(0) {}

MaxPartialFunction::MaxPartialFunction(PartialFunction** _funcs, size_t _size) {
    if(size > MAX_SIZE) throw std::runtime_error("Number of arguments exceeds limit!");

    size = _size;
    funcs = new PartialFunction* [size];
    for (size_t i = 0; i < _size; i++){
        this->funcs[i] = _funcs[i]->clone();
    }
}

MaxPartialFunction::MaxPartialFunction(const MaxPartialFunction& other){
    copyFrom(other);
}

MaxPartialFunction::MaxPartialFunction(MaxPartialFunction&& other) noexcept{
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

MaxPartialFunction& MaxPartialFunction::operator=(MaxPartialFunction&& other) noexcept{
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

int MaxPartialFunction::invoke(int x) const{
    int max = INT_MIN;
    for (size_t i = 0; i < size; i++){
        if(!funcs[i]->isDefined(x)) continue;

        int temp = funcs[i]->invoke(x);
        if (temp > max)
            max = temp;
    }
    return max;
}

MaxPartialFunction::~MaxPartialFunction(){
    free();
}
