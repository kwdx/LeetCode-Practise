/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int a = 0, b = 1;
        if (nums[0] < nums[1]) {
            a = 1;
            b = 0;
        }
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] > nums[a]) {
                b = a;
                a = i;
            } else if (nums[i] > nums[b]) {
                b = i;
            }
        }
        return nums[a] >= (nums[b] << 1) ? a : -1;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入：nums = [3,6,1,0]
     输出：1
     解释：6 是最大的整数，对于数组中的其他整数，6 至少是数组中其他元素的两倍。6 的下标是 1 ，所以返回 1 。
     */
    nums = {3,6,1,0};
    res = 1;
    assert(res == Solution().dominantIndex(nums));

    /**
     输入：nums = [1,2,3,4]
     输出：-1
     解释：4 没有超过 3 的两倍大，所以返回 -1 。
     */
    nums = {1,2,3,4};
    res = -1;
    assert(res == Solution().dominantIndex(nums));

    /**
     输入：nums = [1]
     输出：0
     解释：因为不存在其他数字，所以认为现有数字 1 至少是其他数字的两倍。
     */
    nums = {1};
    res = 0;
    assert(res == Solution().dominantIndex(nums));

    cout << "OK~" << endl;

    return 0;
}
