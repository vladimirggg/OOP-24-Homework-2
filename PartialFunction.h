#pragma once
#include <iostream>
#include "resultPair.h"

const size_t MAX_SIZE = 32;

class PartialFunction{
public:
    virtual PartialFunction* clone() const = 0;
    virtual bool isDefined(int x) const = 0;
    virtual int invoke(int x) const = 0; //invoke / getResult
    virtual ~PartialFunction() = default;
};