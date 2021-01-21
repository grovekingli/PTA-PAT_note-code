//
//  1003_Emergency.cpp
//  PTA&PAT_note&code
//
//  Created by Groveking Li on 2021/1/20.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

vector<int> dijktraPro(int source, int end, vector<vector<int>> map, vector<int> weight,int num)
{
    vector<int> dis, path, collected, pathNums;
    int collectedNum = 0;
    vector<int> totalweight;
    vector<int> res;
    
    // 初始化dis数组
    for (int i = 0; i < num; i++ )
    {
        collected.push_back(0);
        path.push_back(-1);
        dis.push_back(INT_MAX);
        pathNums.push_back(0);
        totalweight.push_back(0);
        if (i == source)
        {
            dis[i] = 0;
            pathNums[i] = 1;
            collected[i] = 1;
            collectedNum ++ ;
            totalweight[i] = weight[source];
        } else if ( map[source][i] != INT_MAX) {
            dis[i] = map[source][i];
            totalweight[i] = weight[source] + weight[i];
            path[i] = source;
            pathNums[i] = 1;
        }
    }
    
    // 开始循环遍历 -- 直到所有点收录完全
    while( collectedNum < num )
    {
        // 筛选出没有被收录的最小距离节点 -- 这一步还不更新dis
        int minDis = INT_MAX;
        int minDisIndex = 0;
        for(int i = 0; i < num; i++)
        {
            if (collected[i] == 1) continue;
            
            if (dis[i] < minDis)
            {
                minDis = dis[i];
                minDisIndex = i;
            }
        }
        
        // 将筛选出最小距离节点纳入'已收集'数组
        collected[minDisIndex] = 1;
        collectedNum ++ ;
        
        // 将刚刚选出来的节点 作为中继节点
        int relayPoint = minDisIndex;
        
        // 更新dis数组__start
        for (size_t i = 0; i < dis.size(); i++)
        {
            // 跳过已收录的节点
            // 该逻辑和下面一个if条件可以合并 为了方便理解所以分开
            if (collected[i] == 1) continue;
            // 和中继节点不连通的节点也不考虑
            if (map[relayPoint][i] == INT_MAX) continue;
            
            // 包含中继节点的路径长
            int relayLen = dis[relayPoint] + map[relayPoint][i];
            if ( relayLen <= dis[i] )
            {
                int totalWeightTemp;
                totalWeightTemp = totalweight[relayPoint] + weight[i];
                if ( relayLen == dis[i] )
                {
                    pathNums[i] = pathNums[relayPoint] + pathNums[i];
                    if (totalWeightTemp > totalweight[i])
                    {
                        totalweight[i] = totalWeightTemp;
                    }
                } else {
                    pathNums[i] = pathNums[relayPoint];
                    totalweight[i] = totalWeightTemp;
                }
                // 如果中继节点长度比原dis中记录的路径短 则进行更新
                dis[i] = relayLen;
                path[i] = relayPoint;
            }
        }
        // 更新dis数组操作__end
    }
    res.push_back(pathNums[end]);
    res.push_back(totalweight[end]);
    
    return res;
}
/**
 配合main 函数使用
 int main()
 {
     vector<vector<int>> cityMap;
     int cityNum;
     int pathNum;
     int start, end;
     vector<int> cityWeight;
     
     cin >> cityNum >> pathNum >> start >> end;
     if (cityNum == 0)
     {
         cout << 0 << " " << 0 <<endl;
         return 0;
     }
     cityMap.resize(cityNum);
     for (int i = 0; i < cityNum; i++)
     {
         int w;
         cin >> w;
         cityWeight.push_back(w);
         cityMap[i].resize(cityNum, INT_MAX);
     }
     for (int i = 0; i < pathNum; i++)
     {
         int s, e;
         int l;
         cin >> s >> e >> l;
         cityMap[s][e] = l;
         cityMap[e][s] = l;
     }
     
     vector<int> res;
     res = dijktraPro(start, end, cityMap, cityWeight, cityNum);
     for (size_t i = 0; i < res.size(); i++)
     {
         cout<< res[i];
         if (i== res.size() - 1)
         {
             cout << endl;
         }else{
             cout << " ";
         }
     }
     return 0;
 }
 */
