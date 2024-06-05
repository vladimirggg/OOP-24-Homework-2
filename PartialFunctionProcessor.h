#pragma once
#include <fstream>
#include <iostream>

#include "PartialFunction.h"
#include "CriteriaPartialFunction.hpp"
#include "Criteria1Func.h"
#include "Criteria2Func.h"
#include "Criteria3Func.h"
#include "MaxPartialFunction.h"
#include "MinPartialFunction.h"


class PartialFunctionProcessor {
    PartialFunction* functor;

    void readStringFromFile(std::ifstream& in, char* buff);
    PartialFunction* readFunctionFromFile(const char* fileName = "func.dat");

public:
    PartialFunctionProcessor();
    void findDefinedPoints() const;
    void invokeWithRange(int a, int b) const;
};
