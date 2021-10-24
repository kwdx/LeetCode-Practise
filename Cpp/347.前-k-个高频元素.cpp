/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// @lc code=start
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
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums, res;
    int k;
    
    /**
     输入: nums = [1,1,1,2,2,3], k = 2
     输出: [1,2]
     */
    nums = {1,1,1,2,2,3};
    k = 2;
    res = {1,2};
    assert(res == Solution().topKFrequent(nums, k));
    
    /**
     输入: nums = [1], k = 1
     输出: [1]
     */
    nums = {1};
    k = 1;
    res = {1};
    assert(res == Solution().topKFrequent(nums, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
