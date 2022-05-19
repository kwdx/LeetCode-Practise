/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0;
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        int mid = (0 + n - 1) >> 1;
        int x = nums[mid];
        for (int num : nums) {
            ans += abs(num - x);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入：nums = [1,2,3]
     输出：2
     解释：
     只需要两步操作（每步操作指南使一个元素加 1 或减 1）：
     [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
     */
    nums = {1,2,3};
    res = 2;
    assert(res == Solution().minMoves2(nums));
    
    /**
     输入：nums = [1,10,2,9]
     输出：16
     */
    nums = {1,10,2,9};
    res = 16;
    assert(res == Solution().minMoves2(nums));
    
    nums = {1,0,0,8,6};
    res = 14;
    assert(res == Solution().minMoves2(nums));
    
    nums = {1,0,0,8};
    res = 9;
    assert(res == Solution().minMoves2(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
