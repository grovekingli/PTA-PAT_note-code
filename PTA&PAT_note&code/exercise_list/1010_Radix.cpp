//
//  1010_Radix.cpp
//  PTA&PAT_note&code
//
//  Created by Groveking Li on 2021/2/13.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;
long long toNumber(char s)
{
    long long n = s - '0';
    if ( n > 9)
    {
        n = 10 + s - 'a';
    }
    return n;
}

long long completeNum(string num, long long radix)
{
    long long n = 0;
    for(int i = 0; i < int(num.size()); i++)
    {
        n += toNumber( num[i] ) * pow( radix, num.size() - i - 1 );
    }
    return n;
}
void radixFun()
{
    string n1, n2;
    long long tag, radix;
    cin >> n1;
    cin >> n2;
    cin >> tag >> radix;
    
    
    long long chosenDecimalNum = 0;
    long long otherDecimalNum = 0;
    string chosenNum, otherNum;
    if ( tag == 1)
    {
        chosenNum = n1;
        otherNum = n2;
    } else {
        chosenNum = n2;
        otherNum = n1;
    }
    // 设定一个最大和最小进制
    long long minRadix = 2;
    long long maxRadix = 3;
    string impossibleStr = "Impossible";
    
    chosenDecimalNum = completeNum(chosenNum, radix);
    otherDecimalNum = completeNum(otherNum, 10);
    for (int i = 0; i < int(otherNum.size()); i++)
    {
        if (toNumber(otherNum[i]) + 1 > minRadix)
        {
            minRadix = toNumber(otherNum[i]) + 1;
        }
    }
    maxRadix = chosenDecimalNum + 1 > minRadix ? chosenDecimalNum + 1 : minRadix;
    
    int resRadix = -1;
    while (minRadix <= maxRadix) {
        long long minOtherNum = 0;
        long long midRadix = (minRadix + maxRadix) / 2;
        if ( midRadix < minRadix)
        {
            midRadix++;
        }
        minOtherNum = completeNum(otherNum, minRadix);
        
        if (chosenDecimalNum == minOtherNum)
        {
            resRadix = minRadix;
            if (midRadix - 1 < minRadix)
            {
                break;
            }
            maxRadix = midRadix - 1;
            continue;
        }
        long long midOtherNum = 0;
        
        midOtherNum = completeNum(otherNum, midRadix);
        
        if (midOtherNum == chosenDecimalNum)
        {
            resRadix = midRadix;
            maxRadix = midRadix - 1;
            continue;
        }
        
        long long maxOtherNum = 0;
        maxOtherNum = completeNum(otherNum, maxRadix);
        if (chosenDecimalNum == maxOtherNum)
        {
            resRadix = maxRadix;
            break;
        }
        
        if (chosenDecimalNum < midOtherNum || midOtherNum < 0)
        {
            maxRadix = midRadix - 1;
            continue;
        }
        
        if (chosenDecimalNum > midOtherNum)
        {
            minRadix = midRadix + 1;
            continue;
        }
    }
    
    if (resRadix > -1)
    {
        cout << resRadix << endl;
        return;
    }
    cout << impossibleStr << endl;
}
