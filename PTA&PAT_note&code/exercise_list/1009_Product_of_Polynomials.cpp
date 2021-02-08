//
//  1009_Product_of_Polynomials.cpp
//  PTA&PAT_note&code
//
//  Created by Groveking Li on 2021/2/8.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

typedef  struct Polynomial
{
    float k;
    int n;
} Polynomial;
void Product_of_Polynomials()
{
    int xNum, yNum;
    vector <Polynomial> x, y;
    cin >> xNum;
    for (int i = 0; i < xNum; i++)
    {
        int n;
        float k;
        Polynomial p;
        cin >> n >> k;
        p.n = n;
        p.k = k;
        x.push_back(p);
    }
    cin >> yNum;
    for (int i = 0; i < yNum; i++)
    {
        int n;
        float k;
        Polynomial p;
        cin >> n >> k;
        p.n = n;
        p.k = k;
        y.push_back(p);
    }
    vector<float> pArr;
    pArr.resize(2001, 0);
    for (int i = 0; i < xNum; i++) {
        for (int j = 0; j < yNum; j++)
        {
            int n;
            float k;
            n = x[i].n + y[j].n;
            k = x[i].k * y[j].k;
            pArr[n] += k;
        }
    }
    
    int resNum = 0;
    
    for (int i = pArr.size(); i >= 0; i--)
    {
        if (pArr[i] != 0)
        {
            resNum++;
        }
    }
    cout << resNum;
    for (int i = pArr.size(); i >= 0; i--)
    {
        if (pArr[i] != 0)
        {
            cout << " " << i << " " << fixed <<setprecision(1) << pArr[i];
        }
    }
    cout << endl;
}
