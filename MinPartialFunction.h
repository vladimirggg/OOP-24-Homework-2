#pragma once
#include "PartialFunction.h"
#include <iostream>

class MinPartialFunction : public PartialFunction{
    PartialFunction* funcs[MAX_SIZE] {nullptr};
    size_t size;

    void copyFrom(const MinPartialFunction& other);
    void moveFrom(MinPartialFunction&& other);
    void free();
public:
    MinPartialFunction();
    MinPartialFunction(PartialFunction** _funcs, size_t _size);
    MinPartialFunction(const MinPartialFunction& other);
    MinPartialFunction(MinPartialFunction&& other);

    MinPartialFunction& operator=(const MinPartialFunction& other);
    MinPartialFunction& operator=(MinPartialFunction&& other);

    PartialFunction* clone() const override;
    bool isDefined(int x) const override;
    resultPair operator()(int x) const override;

    ~MinPartialFunction();
};