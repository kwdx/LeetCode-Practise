/*
 * @lc app=leetcode.cn id=775 lang=cpp
 *
 * [775] 全局倒置与局部倒置
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = (int)nums.size();
        int minSuff = nums[n - 1];
        for (int i = n - 3; i >= 0; --i) {
            if (nums[i] > minSuff) {
                return false;
            }
            minSuff = min(minSuff, nums[i + 1]);
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    bool res;
    
    /**
     输入：nums = [1,0,2]
     输出：true
     解释：有 1 个全局倒置，和 1 个局部倒置。
     */
    nums = {1,0,2};
    res = true;
    assert(res == Solution().isIdealPermutation(nums));
    
    /**
     输入：nums = [1,2,0]
     输出：false
     解释：有 2 个全局倒置，和 1 个局部倒置。
     */
    nums = {1,2,0};
    res = false;
    assert(res == Solution().isIdealPermutation(nums));

    cout << "OK~" << endl;
    
    return 0;
}
