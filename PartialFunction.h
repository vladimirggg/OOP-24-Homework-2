#pragma once

struct resultPair{
    bool first;
    int second;
};

const size_t MAX_SIZE = 32;

class PartialFunction{
public:
    virtual PartialFunction* clone() const = 0;
    virtual bool isDefined(int x) const = 0;
    virtual resultPair operator()(int x) const = 0;
    virtual ~PartialFunction() = default;
};