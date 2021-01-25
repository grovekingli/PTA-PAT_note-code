//
//  1005_Spell_It_Right.cpp
//  PTA&PAT_note&code
//
//  Created by Groveking Li on 2021/1/25.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;
void Spell_It_Right()
{
    map<int, string> mapNumber;
    mapNumber[0] = "zero";
    mapNumber[1] = "one";
    mapNumber[2] = "two";
    mapNumber[3] = "three";
    mapNumber[4] = "four";
    mapNumber[5] = "five";
    mapNumber[6] = "six";
    mapNumber[7] = "seven";
    mapNumber[8] = "eight";
    mapNumber[9] = "nine";

    string num;
    int sum = 0;
    cin >> num;
    for (std::size_t i = 0; i < num.size(); i++)
    {
        int single;
        single = num[i]- '0';
        sum += single;
    }
    string sumStr = std::to_string(sum);
    for (std::size_t i = 0; i < sumStr.size(); i++)
    {
        int single;
        single = sumStr[i]- '0';
        cout << mapNumber[single];
        if (i != sumStr.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

}
