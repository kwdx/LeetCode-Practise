/*
 * @lc app=leetcode.cn id=2293 lang=cpp
 *
 * [2293] 极大极小游戏
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = (int)nums.size();
        while (n != 1) {
            int m = n / 2;
            for (int i = 0; i < m; ++i) {
                if (i % 2 == 0) {
                    nums[i] = min(nums[2 * i], nums[2 * i + 1]);
                } else {
                    nums[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
            }
            n = m;
        }
        return nums[0];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;

    /**
     输入：nums = [1,3,5,2,4,8,2,2]
     输出：1
     解释：重复执行算法会得到下述数组。
     第一轮：nums = [1,5,4,2]
     第二轮：nums = [1,4]
     第三轮：nums = [1]
     1 是最后剩下的那个数字，返回 1 。
     */
    nums = {1,3,5,2,4,8,2,2};
    res = 1;
    assert(res == Solution().minMaxGame(nums));
    
    /**
     输入：nums = [3]
     输出：3
     解释：3 就是最后剩下的数字，返回 3 。
     */
    nums = {3};
    res = 3;
    assert(res == Solution().minMaxGame(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
