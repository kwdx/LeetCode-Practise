/*
 * @lc app=leetcode.cn id=1608 lang=cpp
 *
 * [1608] 特殊数组的特征值
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] >= i && (i == n || nums[i] < i)) {
                return i;
            }
        
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入：nums = [3,5]
     输出：2
     解释：有 2 个元素（3 和 5）大于或等于 2 。
     */
    nums = {3,5};
    res = 2;
    assert(res == Solution().specialArray(nums));
    
    /**
     输入：nums = [0,0]
     输出：-1
     解释：没有满足题目要求的特殊数组，故而也不存在特征值 x 。
     如果 x = 0，应该有 0 个元素 >= x，但实际有 2 个。
     如果 x = 1，应该有 1 个元素 >= x，但实际有 0 个。
     如果 x = 2，应该有 2 个元素 >= x，但实际有 0 个。
     x 不能取更大的值，因为 nums 中只有两个元素。
     */
    nums = {0,0};
    res = -1;
    assert(res == Solution().specialArray(nums));
    
    /**
     输入：nums = [0,4,3,0,4]
     输出：3
     解释：有 3 个元素大于或等于 3 。
     */
    nums = {0,4,3,0,4};
    res = 3;
    assert(res == Solution().specialArray(nums));
    
    /**
     输入：nums = [3,6,7,7,0]
     输出：-1
     */
    nums = {3,6,7,7,0};
    res = -1;
    assert(res == Solution().specialArray(nums));

    cout << "OK~" << endl;
    
    return 0;
}
