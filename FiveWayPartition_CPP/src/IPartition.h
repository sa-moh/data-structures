#pragma once

template <class T>
class IPartition
{
public:
    virtual void partition(T *arr, const T *pivots, int *q, int p, int r, int pivotsCount) = 0;
};