#pragma once
#include "PartialFunction.h"
#include <iostream>

class MinPartialFunction : public PartialFunction{
    PartialFunction** funcs;
    size_t size;

    void copyFrom(const MinPartialFunction& other);
    void moveFrom(MinPartialFunction&& other) noexcept;
    void free();
public:
    MinPartialFunction();
    MinPartialFunction(PartialFunction** _funcs, size_t _size);
    MinPartialFunction(const MinPartialFunction& other);
    MinPartialFunction(MinPartialFunction&& other) noexcept;

    MinPartialFunction& operator=(const MinPartialFunction& other);
    MinPartialFunction& operator=(MinPartialFunction&& other) noexcept;

    PartialFunction* clone() const override;
    bool isDefined(int x) const override;
    int invoke(int x) const override;

    ~MinPartialFunction();
};