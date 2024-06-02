#pragma once
#include <iostream>
#include "CriteriaType.h"

class Criteria3Func : public CriteriaType{
    int args[MAX_SIZE];
    size_t size;

public:
    Criteria3Func(int* _args, size_t _size);

    CriteriaType* clone() const override;
    bool isDefined(int x) const override;
    resultPair operator()(int x) const override;
    ~Criteria3Func() = default;
};