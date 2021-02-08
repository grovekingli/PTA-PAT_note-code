//
//  1008_Elevator.cpp
//  PTA&PAT_note&code
//
//  Created by Groveking Li on 2021/2/8.
//

#include <stdio.h>
void Elevator()
{
    #include <iostream>
    #include <string>
    #include <sstream>
    #include <iomanip>
    #include <vector>
    #include <list>
    #include <algorithm>
    #include <map>
    using namespace std;
    void fun()
    {
        int num;
        int time = 0;
        int lastLevel;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int n;
            cin >> n;
            if (i == 0) {
                time += n * 6;
            } else if (lastLevel < n) {
                time += (n - lastLevel) * 6;
            } else if (lastLevel > n) {
                time += (lastLevel - n) * 4;
            }
            time += 5;
            
            lastLevel = n;
        }
        cout << time << endl;
    }
}
