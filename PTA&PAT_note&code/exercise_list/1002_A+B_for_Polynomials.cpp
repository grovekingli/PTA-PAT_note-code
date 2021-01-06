//
//  1002_A+B_for_Polynomials.cpp
//  PTA&PAT_note&code
//
//  Created by Groveking Li on 2021/1/6.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

typedef struct ExponentMapItem
{
    double val;
    int n;
    bool hasVal = false;
} ExObj;
void AB_for_Polynomials() {
    int aLen = 0, bLen;
    double exMap[1001] = {0.0};
    int resLen = 0;
    int n;
    double an;
    cin >> aLen;
    for (int i = 0; i<aLen; i++)
    {
        cin >> n;
        cin >> an;
        exMap[n] += an;
    }
    
    cin >> bLen;
    for (int i = 0; i<bLen; i++)
    {
        cin >> n;
        cin >> an;
        exMap[n] += an;
    }
    for (int i = 1000; i>=0; i--) {
        if (exMap[i] != 0) resLen ++;
    }
    cout << resLen;
    for (int i = 1000; i>=0; i--) {
        if (exMap[i] != 0)
        {
            cout << ' ';
            cout << i;
            cout << ' ';
            cout << setiosflags(ios::fixed) << setprecision(1) << exMap[i];
        }
    }
    cout<<endl;
}

