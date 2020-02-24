//
//  _451_根据字符出现频率排序.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/24.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/sort-characters-by-frequency/

#include <stdio.h>
#include <string>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string res;
        map<char, int> m;
        for(auto val:s)
            m[val]++;

        priority_queue<pair<int, char>> pq;
        for(auto val:m)
            pq.push(make_pair(val.second, val.first));
        
        while (!pq.empty()) {
            auto top = pq.top();
            int num = top.first;
            while(num--)
                res+=top.second;
            pq.pop();
        }
        return res;
    }
};

/**
 示例 1:

 输入:
 "tree"

 输出:
 "eert"

 示例 2:

 输入:
 "cccaaa"

 输出:
 "cccaaa"

 示例 3:

 输入:
 "Aabb"

 输出:
 "bbAa"
 */
int main(int argc, const char * argv[]) {
    Solution solution = Solution();
//    string result = solution.frequencySort("tree");
    string result = solution.frequencySort("cccaaa");
    printf("%s\n", result.c_str());

    return 0;
}
