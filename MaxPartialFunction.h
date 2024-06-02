#pragma once
#include "PartialFunction.h"
#include <iostream>

class MaxPartialFunction: public PartialFunction{
    PartialFunction** funcs;
    size_t size;

    void copyFrom(const MaxPartialFunction& other);
    void moveFrom(MaxPartialFunction&& other) noexcept;
    void free();
public:
    MaxPartialFunction();
    MaxPartialFunction(PartialFunction** _funcs, size_t _size);
    MaxPartialFunction(const MaxPartialFunction& other);
    MaxPartialFunction(MaxPartialFunction&& other) noexcept;

    MaxPartialFunction& operator=(const MaxPartialFunction& other);
    MaxPartialFunction& operator=(MaxPartialFunction&& other) noexcept;

    PartialFunction* clone() const override;
    bool isDefined(int x) const override;
    int invoke(int x) const override;

    ~MaxPartialFunction();
};