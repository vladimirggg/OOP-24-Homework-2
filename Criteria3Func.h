#pragma once
#include <iostream>
#include "PartialFunction.h"

class Criteria3Func : public PartialFunction
{
    int args[MAX_SIZE];
    int results[MAX_SIZE];
    size_t size;
    int getIndex(int x) const;
public:
    Criteria3Func(int* _args, size_t _size);
    
    PartialFunction* clone() const override;
    bool isDefined(int x) const override;
    resultPair operator()(int x) const override;
    ~Criteria3Func() = default;
};