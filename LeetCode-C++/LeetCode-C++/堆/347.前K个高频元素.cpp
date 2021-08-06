//
//  347.前K个高频元素.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/top-k-frequent-elements/

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counts;
        for (auto num : nums) {
            counts[num]++;
        }
        
        vector<pair<int, int>> entries(counts.begin(), counts.end());
        int begin = 0;
        int end = (int)entries.size();
        int resultIdx = k - 1;
        int pivotIdx = 0;
        while ((pivotIdx = pivotIndex(entries, begin, end)) != resultIdx) {
            if (pivotIdx > resultIdx) {
                end = pivotIdx;
            } else {
                begin = pivotIdx + 1;
            }
        }
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(entries[i].first);
        }
        
        return result;
    }
    
    int pivotIndex(vector<pair<int, int>>& entries, int begin, int end) {
        int newBegin = begin + (end - begin) / 2;
        pair<int, int> tmp = entries[begin];
        entries[begin] = entries[newBegin];
        entries[newBegin] = tmp;
        
        pair<int, int> pivot = entries[begin];
        end --;
        
        while (begin < end) {
            while (begin < end) {
                if (pivot.second > entries[end].second) {
                    end --;
                } else {
                    entries[begin++] = entries[end];
                    break;
                }
            }
            while (begin < end) {
                if (pivot.second < entries[begin].second) {
                    begin ++;
                } else {
                    entries[end--] = entries[begin];
                    break;
                }
            }
        }
        
        entries[begin] = pivot;
        return begin;
    }
};

/**
 输入: nums = [1,1,1,2,2,3], k = 2
 输出: [1,2]

 输入: nums = [1], k = 1
 输出: [1]
*/
/**
int main(int argc, const char * argv[]) {
//    vector<int> nums = {1, 1, 1, 2, 2, 3};
//    vector<int> nums = {1};
    vector<int> nums = {3, 1, 2, 1, 3, 2, 1, 3};

    Solution solution = Solution();
    vector<int> result = solution.topKFrequent(nums, 2);
    for (auto num : result) {
        printf("%d ", num);
    }
    printf("\n");

    return 0;
}
*/
