/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 *
 * [2016] 增量元素之间的最大差值
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int n = (int)nums.size();
        for (int i = 1, val = nums[0]; i < n; ++i) {
            if (nums[i] > val) {
                ans = max(ans, nums[i] - val);
            }
            val = min(val, nums[i]);
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
     输入：nums = [7,1,5,4]
     输出：4
     解释：
     最大差值出现在 i = 1 且 j = 2 时，nums[j] - nums[i] = 5 - 1 = 4 。
     注意，尽管 i = 1 且 j = 0 时 ，nums[j] - nums[i] = 7 - 1 = 6 > 4 ，但 i > j 不满足题面要求，所以 6 不是有效的答案。
     */
    nums = {7,1,5,4};
    res = 4;
    assert(res == Solution().maximumDifference(nums));

    /**
     输入：nums = [9,4,3,2]
     输出：-1
     解释：
     不存在同时满足 i < j 和 nums[i] < nums[j] 这两个条件的 i, j 组合。
     */
    nums = {9,4,3,2};
    res = -1;
    assert(res == Solution().maximumDifference(nums));

    /**
     输入：nums = [1,5,2,10]
     输出：9
     解释：
     最大差值出现在 i = 0 且 j = 3 时，nums[j] - nums[i] = 10 - 1 = 9 。
     */
    nums = {1,5,2,10};
    res = 9;
    assert(res == Solution().maximumDifference(nums));

    cout << "OK~" << endl;
    
    return 0;
}
