/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;
        // 排队顶
        vector<int> tops(n);
        // 每张牌为尾的子序列长度
        vector<vector<pair<int, int>>> lens;
        
        int piles = 0;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            int left = 0, right = piles;
            while (left < right) {
                int mid = left + ((right - left) >> 1);
                if (tops[mid] >= num) {
                    right = mid;
                } else if (tops[mid] < num) {
                    left = mid + 1;
                }
            }
            
            if (left == piles) {
                ++piles;
                lens.push_back({});
            }
            tops[left] = num;
            
            if (left > 0) {
                int len = 0;
                for (pair<int, int> & a : lens[left - 1]) {
                    if (a.second < num)
                        len += a.first;
                }
                lens[left].push_back({len, num});
            } else {
                lens[0].push_back({1, num});
            }
        }
        
        int res = 0;
        for (pair<int, int> & a : lens[piles - 1]) {
            res += a.first;
        }
        return res;
        
//        return accumulate(lens[piles - 1].begin(), lens[piles - 1].end(), 0);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums;
    int res;
    
    /**
     输入: [1,3,5,4,7]
     输出: 2
     解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
     */
    nums = {1,3,5,4,7};
    res = 2;
    assert(res == Solution().findNumberOfLIS(nums));

    /**
     输入: [2,2,2,2,2]
     输出: 5
     解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
     */
    nums = {2,2,2,2,2};
    res = 5;
    assert(res == Solution().findNumberOfLIS(nums));
    
    /**
     输入: [1,2,4,3,5,4,7,2]
     输出: 3
     解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
     */
    nums = {1,2,4,3,5,4,7,2};
    res = 3;
    assert(res == Solution().findNumberOfLIS(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
