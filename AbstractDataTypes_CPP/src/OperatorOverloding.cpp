//
// Created by user on 11/24/2025.
//

#include "OperatorOverloding.h"
#include "iostream"
using namespace std;


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
    x x2(2);
    x x5(5);
    if(x2 < x5)
        cout << "x2 < x5" << endl;
    else
        cout << "x2 >= x5" << endl;
    return 0;

}