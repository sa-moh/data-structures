//
// Created by user on 11/24/2025.
//

#include "OperatorOverloding.h"
#include "iostream"
using namespace std;

template <class T>
class x{
    int evalue;
public:
    x(int value){
        evalue =  value;
    }
    bool operator < (const x& x)
    {
        return this->evalue < x.evalue;
    }
};
int main(){
    cout << "hey";
}