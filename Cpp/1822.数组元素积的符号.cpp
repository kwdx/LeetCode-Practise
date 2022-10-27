/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 *
 * [1822] 数组元素积的符号
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (auto & num : nums) {
            if (num == 0) return 0;
            if (num < 0) sign = -sign;
        }
        return sign;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入：nums = [-1,-2,-3,-4,3,2,1]
     输出：1
     解释：数组中所有值的乘积是 144 ，且 signFunc(144) = 1
     */
    nums = {-1,-2,-3,-4,3,2,1};
    res = 1;
    assert(res == Solution().arraySign(nums));
    
    /**
     输入：nums = [1,5,0,2,-3]
     输出：0
     解释：数组中所有值的乘积是 0 ，且 signFunc(0) = 0
     */
    nums = {1,5,0,2,-3};
    res = 0;
    assert(res == Solution().arraySign(nums));
    
    /**
     输入：nums = [-1,1,-1,1,-1]
     输出：-1
     解释：数组中所有值的乘积是 -1 ，且 signFunc(-1) = -1
     */
    nums = {-1,1,-1,1,-1};
    res = -1;
    assert(res == Solution().arraySign(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
