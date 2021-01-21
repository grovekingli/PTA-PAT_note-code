//
//  dijktra.cpp
//  PTA&PAT_note&code
//
//  Created by Groveking Li on 2021/1/13.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> dijktra(int start, int end, vector<vector<int>> map, int num)
{
    vector<int> dis;
    vector<int> isShortArr;
    vector<int> path;
    int current;

    for (int i = 0; i < num; i++)
    {
        if (start == i)
        {
            dis.push_back(0);
        }
        else if (map[start][i] && map[start][i]!=0)
        {
            dis.push_back(map[start][i]);
        } else {
            dis.push_back(INT_MAX);
        }
        isShortArr.push_back(0);
    }
    current = start;
    path.push_back(current);
    isShortArr[current] = 1;
    int updateNum = 1;

    while (updateNum != num)
    {
        int min = INT_MAX;
        int currentTemp = current;
        for(int i = 0; i < num; i++)
        {
            if (i == current || map[current][i] == INT_MAX || isShortArr[i] == 1) {
                continue;
            }
            int lastMin;
            lastMin = dis[path.back()];
            if (map[current][i] + lastMin < dis[i])
            {
                dis[i] = map[current][i] + lastMin;
            }
            if (map[current][i] + lastMin <= min)
            {
                currentTemp = i;
                min = map[current][i] + lastMin;
            }
        }
        current = currentTemp;
        isShortArr[current] = 1;
        path.push_back(current);
        updateNum ++;
    }
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    return dis;
}
