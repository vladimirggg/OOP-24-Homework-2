#include "Criteria1Func.h"

void Criteria1Func::free() {
    delete[] results;
}

void Criteria1Func::copyFrom(const Criteria1Func& other){
    results = new int[size];
    for (int i = 0; i < other.size; ++i)
        results[i] = other.results[i];
}

void Criteria1Func::moveFrom(Criteria1Func&& other) noexcept{
    results = other.results;
    other.results = nullptr;
}

Criteria1Func::Criteria1Func() : CriteriaType(), results(nullptr){}

Criteria1Func::Criteria1Func(int* _args, int* _results, size_t _size) : CriteriaType(_args, _size){
    results = new int[size];
    for (size_t i = 0; i < size; i++)
        results[i] = _results[i];
}

Criteria1Func::Criteria1Func(const Criteria1Func& other) : CriteriaType(other){
    copyFrom(other);
}

Criteria1Func::Criteria1Func(Criteria1Func&& other) noexcept: CriteriaType(std::move(other)){
    moveFrom(std::move(other));
}

Criteria1Func& Criteria1Func::operator=(const Criteria1Func &other) {
    CriteriaType::operator=(other);
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

Criteria1Func& Criteria1Func::operator=(Criteria1Func &&other) noexcept{
    CriteriaType::operator=(std::move(other));
    if(this != &other){
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

CriteriaType* Criteria1Func::clone() const{
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

Criteria1Func::~Criteria1Func(){
    free();
}