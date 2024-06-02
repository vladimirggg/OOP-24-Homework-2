#include "CriteriaType.h"

const size_t MAX_SIZE = 0;

void CriteriaType::free(){
    delete[] args;
    size = 0;
}

void CriteriaType::copyFrom(const CriteriaType &other) {
    size = other.size;
    args = new int[size];

    for (int i = 0; i < size; ++i)
        args[i] = other.args[i];
}

void CriteriaType::moveFrom(CriteriaType &&other) noexcept{
    size = other.size;
    args = other.args;
    other.size = 0;
    other.args = nullptr;
}

int CriteriaType::getIndex(int x) const{
    for(int i = 0; i < size; ++i)
        if(args[i] == x) return i;

    return -1;
}

CriteriaType::CriteriaType() : args(nullptr), size(0){}

CriteriaType::CriteriaType(const int* _args, size_t _size){
    if(_size > CriteriaType::MAX_SIZE)
        throw std::invalid_argument("Too many arguments!");

    size = _size;
    args = new int[size];
    for (int i = 0; i < size; ++i)
        args[i] = _args[i];
}

CriteriaType::CriteriaType(const CriteriaType& other){
    copyFrom(other);
}

CriteriaType::CriteriaType(CriteriaType&& other) noexcept{
    moveFrom(std::move(other));
}

CriteriaType& CriteriaType::operator=(const CriteriaType &other) {
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

CriteriaType& CriteriaType::operator=(CriteriaType &&other) noexcept{
    if(this != &other){
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

CriteriaType::~CriteriaType() {
    free();
}
