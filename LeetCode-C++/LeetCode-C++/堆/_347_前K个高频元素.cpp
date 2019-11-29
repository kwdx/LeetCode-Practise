//
//  _347_前K个高频元素.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_347_前K个高频元素.hpp"
#include <map>

vector<int> _347_前K个高频元素::topKFrequent(vector<int>& nums, int k) {
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

    int _347_前K个高频元素::pivotIndex(vector<pair<int, int>>& entries, int begin, int end) {
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
