//
//  1004_Counting_Leaves.cpp
//  PTA&PAT_note&code
//
//  Created by Groveking Li on 2021/1/25.
//

#include <stdio.h>
struct Node {
    int level = -1;
    int parent = -1;
    int isActive = 0;
    vector<int> sonNodes = {};
};
int dfs(Node* node, vector<int> &leafNum, int level, vector<Node> &tree)
{
    node->level = level;
    if (node->sonNodes.size() == 0) {
        leafNum[level] = leafNum[level] + 1;
        return level;
    } else {
        int sonLevel = level + 1;
        int resLevel = level;
        int tempLevel = 0;
        for (std::size_t  i = 0; i < node->sonNodes.size(); i++)
        {
            int sonNodeKey = node->sonNodes[i];
            Node* sonNode = &tree[sonNodeKey - 1];
            tempLevel = dfs(sonNode, leafNum, sonLevel, tree);
            resLevel = tempLevel > resLevel ? tempLevel : resLevel;
        }
        return resLevel;
    }
}
void counting_Leaves()
{
    int nodeNum, noLeafNum;
    cin >> nodeNum >> noLeafNum;
    vector<Node> tree;
    vector<int> leafNum;
    tree.resize(101);
    tree[0].level = 0;
    tree[0].isActive = 1;
    tree[0].sonNodes = {};
    leafNum.resize(101);
    int maxKey = 1;

    for (int i = 0; i < noLeafNum; i++)
    {
        int mainNodeKey;
        int sonNum;
        cin >> mainNodeKey >> sonNum;
        if (mainNodeKey > maxKey){
            maxKey = mainNodeKey;
        }
        Node* mainNode = &tree[mainNodeKey - 1];

        mainNode -> isActive = 1;
        mainNode -> sonNodes.resize(sonNum);

        for(int j = 0; j < sonNum; j++)
        {
            int sonNodeKey;
            cin >> sonNodeKey;
            if (sonNodeKey > maxKey){
                maxKey = sonNodeKey;
            }
            Node* sonNode = &tree[sonNodeKey - 1];
            sonNode->parent = mainNodeKey;
            sonNode->isActive = 1;
            mainNode->sonNodes[j] = sonNodeKey;
        }
    }
    int maxLevel = 0;
    maxLevel = dfs(&tree[0], leafNum, 0, tree);

    for (int i = 0; i <= maxLevel; i++)
    {
        cout << leafNum[i];
        if ( i < maxLevel)
        {
            cout << ' ';
        }
    }
    cout << endl;
}
