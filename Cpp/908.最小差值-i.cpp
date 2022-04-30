/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int a = nums[0], b = nums[0];
        for (int num : nums) {
            a = max(num, a);
            b = min(num, b);
        }
        return max(0, a - b - k * 2);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int k;
    int res;
    
    /**'
     输入：nums = [1], k = 0
     输出：0
     解释：分数是 max(nums) - min(nums) = 1 - 1 = 0。
     */
    nums = {1};
    k = 0;
    res = 0;
    assert(res == Solution().smallestRangeI(nums, k));
    
    /**'
     输入：nums = [0,10], k = 2
     输出：6
     解释：将 nums 改为 [2,8]。分数是 max(nums) - min(nums) = 8 - 2 = 6。
     */
    nums = {0,10};
    k = 2;
    res = 6;
    assert(res == Solution().smallestRangeI(nums, k));
    
    /**'
     输入：nums = [1,3,6], k = 3
     输出：0
     解释：将 nums 改为 [4,4,4]。分数是 max(nums) - min(nums) = 4 - 4 = 0。
     */
    nums = {1,3,6};
    k = 3;
    res = 0;
    assert(res == Solution().smallestRangeI(nums, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
