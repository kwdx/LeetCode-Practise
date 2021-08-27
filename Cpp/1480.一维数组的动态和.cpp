/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        res[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            res[i] = res[i - 1] + nums[i];
        }
        return res;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    vector<int> nums;
    vector<int> res;
    
    /**
     输入：nums = [1,2,3,4]
     输出：[1,3,6,10]
     解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。
     */
    nums = {1,2,3,4};
    res = {1,3,6,10};
    assert(res == Solution().runningSum(nums));
    
    /**
     输入：nums = [1,1,1,1,1]
     输出：[1,2,3,4,5]
     解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。
     */
    nums = {1,1,1,1,1};
    res = {1,2,3,4,5};
    assert(res == Solution().runningSum(nums));
    
    /**
     输入：nums = [3,1,2,10,1]
     输出：[3,4,6,16,17]
     */
    nums = {3,1,2,10,1};
    res = {3,4,6,16,17};
    assert(res == Solution().runningSum(nums));
    
    cout << "OK~" << endl;
    
    return 0;
};
