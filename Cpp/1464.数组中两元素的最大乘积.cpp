/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        return (nums[n - 2] - 1) * (nums[n - 1] - 1);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int  res;
    
    /**
     输入：nums = [3,4,5,2]
     输出：12
     解释：如果选择下标 i=1 和 j=2（下标从 0 开始），则可以获得最大值，(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12 。
     */
    nums = {3,4,5,2};
    res = 12;
    assert(res == Solution().maxProduct(nums));
    
    /**
     输入：nums = [1,5,4,5]
     输出：16
     解释：选择下标 i=1 和 j=3（下标从 0 开始），则可以获得最大值 (5-1)*(5-1) = 16 。
     */
    nums = {1,5,4,5};
    res = 16;
    assert(res == Solution().maxProduct(nums));
    
    /**
     输入：nums = [3,7]
     输出：12
     */
    nums = {3,7};
    res = 12;
    assert(res == Solution().maxProduct(nums));

    cout << "OK~" << endl;
    
    return 0;
}
