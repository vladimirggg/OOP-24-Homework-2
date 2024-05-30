#pragma once
#include <iostream>
#include "PartialFunction.h"


class Criteria2Func : public PartialFunction
{
    int args[MAX_SIZE];
    size_t size;
    int getIndex(int x) const;
public:
    Criteria2Func(int* _args, size_t _size);

    PartialFunction* clone() const override;
    bool isDefined(int x) const override;
    resultPair operator()(int x) const override;
    ~Criteria2Func() = default;
};