//
//  1001_A+B_Format.cpp
//  PTA&PAT_note&code
//
//  Created by Groveking Li on 2021/1/6.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string FormatNum (int a, int b)
{
    string res;
    int resNum = a + b;
    string sumStr = resNum >= 0 ? to_string(resNum) : to_string(0-resNum);
    int strLen = sumStr.length();
    for(int i=0; i<strLen; i++)
    {
        res.insert(0, 1, sumStr[strLen - i - 1]);
        if((i+1)%3 == 0 && i!= strLen-1 && i!=0 && i+1 >= 3)
        {
            res.insert(0, 1,',');
        }
    }
    if(resNum < 0)
    {
        res.insert(0, 1,'-');
    }
    
    return res;
}

void AB_Format() {
    int a;
    int b;
    cin >> a >> b;
    cout<<FormatNum(a, b)<<endl;
}
