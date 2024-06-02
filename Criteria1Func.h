#pragma once
#include <iostream>
#include "CriteriaType.h"

class Criteria1Func : public CriteriaType{
    int *results;

    void free();
    void copyFrom(const Criteria1Func& other);
    void moveFrom(Criteria1Func&& other) noexcept;
public:
    Criteria1Func();
    Criteria1Func(int* _args, int* _results, size_t _size);
    Criteria1Func(const Criteria1Func& other);
    Criteria1Func(Criteria1Func&& other) noexcept;
    Criteria1Func& operator=(const Criteria1Func& other);
    Criteria1Func& operator=(Criteria1Func&& other) noexcept;

    CriteriaType* clone() const override;
    bool isDefined(int x) const override;
    resultPair operator()(int x) const override;
    ~Criteria1Func();
};