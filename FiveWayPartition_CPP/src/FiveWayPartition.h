// Copyright (C) Kamaledin Ghiasi-Shirazi, Ferdowsi Univerity of Mashhad, 2020 (1399 Hijri Shamsi)
//
// 	Author:		Ali Moghaddas-zadeh

#pragma once


template <class T>
class FiveWayPartition : public IPartition<T>
{
public:
    /* Partition data such that
        data < pivot1 are in range [p,q1)
        data == pivot1 are in range [q1,q2)
        data < pivot2 and > pivot1 are in range [q2,q3)
        data == pivot2 are in range [q3,q4)
        data > pivot2 are in range [q4+1,r]
    */

    virtual void partition(T *arr, const T *pivots, int *q, int p, int r, int pivotsCount)
    {
        int i = p, j = p, k = p, n = r + 1, m = r + 1;
        while(k < m) {
            if (arr[k] > pivots[0] && arr[k] < pivots[1]) {
                k++;

            } else if (arr[k] == pivots[1]) {
                T temp = arr[k];
                arr[m - 1] = arr[k];
                arr[k] = temp;
                m--;


            } else if (arr[k] == pivots[0]) {
                T temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
                j++;
                k++;
            } else if (arr[k] < pivots[0]) {
                T temp = arr[k];
                arr[k] = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                i++;
                j++;
                k++;


            } else if (arr[k] > pivots[1]) {
                T temp = arr[k];
                arr[k] = arr[m - 1];
                arr[m - 1] = arr[n - 1];
                arr[n - 1] = temp;
                n--;
                m--;

            }
            q[0] = i;
            q[1] = j;
            q[2] = m;
            q[3] = n;
        }
    }
};
