/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> ans;
        int win1 = 0, maxWin1 = 0, maxWin1Idx = 0;
        int win2 = 0, maxWin12 = 0, maxWin12Idx1 = 0;
        int win3 = 0, maxTotal = 0, maxWin12Idx2 = 0;
        for (int i = k * 2; i < nums.size(); ++i) {
            win1 += nums[i - k * 2];
            win2 += nums[i - k];
            win3 += nums[i];
            if (i >= k * 3 - 1) {
                if (win1 > maxWin1) {
                    maxWin1 = win1;
                    maxWin1Idx = i - k * 3 + 1;
                }
                if (maxWin1 + win2 > maxWin12) {
                    maxWin12 = maxWin1 + win2;
                    maxWin12Idx1 = maxWin1Idx;
                    maxWin12Idx2 = i - k * 2 + 1;
                }
                if (maxWin12 + win3 > maxTotal) {
                    maxTotal = maxWin12 + win3;
                    ans = {maxWin12Idx1, maxWin12Idx2, i - k + 1};
                }
                win1 -= nums[i - k * 3 + 1];
                win2 -= nums[i - k * 2 + 1];
                win3 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int k;
    vector<int> res;
    
    /**
     输入：nums = [1,2,1,2,6,7,5,1], k = 2
     输出：[0,3,5]
     解释：子数组 [1, 2], [2, 6], [7, 5] 对应的起始下标为 [0, 3, 5]。
     也可以取 [2, 1], 但是结果 [1, 3, 5] 在字典序上更大。
     */
    nums = {1,2,1,2,6,7,5,1};
    k = 2;
    res = {0,3,5};
    assert(res == Solution().maxSumOfThreeSubarrays(nums, k));
    
    /**
     输入：nums = [1,2,1,2,1,2,1,2,1], k = 2
     输出：[0,2,4]
     */
    nums = {1,2,1,2,1,2,1,2,1};
    k = 2;
    res = {0,2,4};
    assert(res == Solution().maxSumOfThreeSubarrays(nums, k));

    cout << "OK~" << endl;

    return 0;
}
