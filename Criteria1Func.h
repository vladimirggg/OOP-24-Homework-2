#pragma once
#include <iostream>
#include "PartialFunction.h"

class Criteria1Func : public PartialFunction
{
    int args[MAX_SIZE];
    int results[MAX_SIZE];
    size_t size;
    int getIndex(int x) const;
public:
    Criteria1Func(int* _args, int* _results, size_t _size);

    PartialFunction* clone() const override;
    bool isDefined(int x) const override;
    resultPair operator()(int x) const override;
    ~Criteria1Func() = default;
};