#pragma once
#include "PartialFunction.h"
#include <iostream>

class MaxPartialFunction: public PartialFunction{
    PartialFunction* funcs[MAX_SIZE] {nullptr};
    size_t size;

    void copyFrom(const MaxPartialFunction& other);
    void moveFrom(MaxPartialFunction&& other);
    void free();
public:
    MaxPartialFunction();
    MaxPartialFunction(PartialFunction** _funcs, size_t _size);
    MaxPartialFunction(const MaxPartialFunction& other);
    MaxPartialFunction(MaxPartialFunction&& other);

    MaxPartialFunction& operator=(const MaxPartialFunction& other);
    MaxPartialFunction& operator=(MaxPartialFunction&& other);

    PartialFunction* clone() const override;
    bool isDefined(int x) const override;
    resultPair operator()(int x) const override;

    ~MaxPartialFunction();
};