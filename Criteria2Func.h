#pragma once
#include <iostream>
#include "CriteriaType.h"


class Criteria2Func : public CriteriaType{
public:
    Criteria2Func(int* _args, size_t _size);

    CriteriaType* clone() const override;
    bool isDefined(int x) const override;
    resultPair operator()(int x) const override;
    ~Criteria2Func() = default;
};