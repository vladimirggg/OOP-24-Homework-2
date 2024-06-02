#pragma once
#include <iostream>
#include "resultPair.h"

class CriteriaType {
protected:
    static const size_t MAX_SIZE = 32;
    int *args;
    size_t size;

    void free();
    void copyFrom(const CriteriaType& other);
    void moveFrom(CriteriaType&& other) noexcept;

    int getIndex(int x) const;
public:
    CriteriaType();
    CriteriaType(const int *_args, size_t _size);
    CriteriaType(const CriteriaType& other);
    CriteriaType(CriteriaType&& other) noexcept;
    CriteriaType& operator=(const CriteriaType& other);
    CriteriaType& operator=(CriteriaType&& other) noexcept;

    virtual bool isDefined(int x) const = 0;
    virtual CriteriaType* clone() const = 0;
    virtual resultPair operator()(int x) const = 0;
    virtual ~CriteriaType();
};
