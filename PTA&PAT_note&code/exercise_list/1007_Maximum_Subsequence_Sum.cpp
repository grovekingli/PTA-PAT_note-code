//
//  1007_Maximum_Subsequence_Sum.cpp
//  PTA&PAT_note&code
//
//  Created by Groveking Li on 2021/2/6.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;
void Maximum_Subsequence_Sum()
{
    vector<int> numberArr;
    vector<int> dp;
    map<int, int*> dpMap;
    int num;
    int maxIndex = 0;

    cin >> num;
    numberArr.resize(num);
    dp.resize(num);
    for (int i = 0; i < num; i++)
    {
        int j;
        cin >> j;
        numberArr[i] = j;
        int* mapVal = new int[2];
        mapVal[0] = i;
        mapVal[1] = i;
        if ( i== 0)
        {
            dp[i] = j;
            maxIndex = i;
            dpMap[i] = mapVal;
        } else {
            int dpValAddJ = dp[i - 1] + j;
            if (dpValAddJ > j)
            {
                dp[i] = dpValAddJ;
                mapVal[0] = dpMap[i-1][0];
            } else {
                dp[i] = j;
            }
            dpMap[i] = mapVal;
            if(dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }
    }
    if (dp[maxIndex] < 0) {
        cout << 0 << " ";
        cout << numberArr[0] << " ";
        cout << numberArr[num - 1] << endl;
    } else {
        cout << dp[maxIndex] << " ";
        cout << numberArr[dpMap[maxIndex][0]] << " ";
        cout << numberArr[dpMap[maxIndex][1]] << endl;
    }
}
