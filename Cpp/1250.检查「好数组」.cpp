/*
 * @lc app=leetcode.cn id=1250 lang=cpp
 *
 * [1250] 检查「好数组」
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int divisor = nums[0];
        for (int num : nums) {
            divisor = gcd(divisor, num);
            if (divisor == 1) {
                break;
            }
        }
        return divisor == 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    bool res;
    
    /**
     输入：nums = [12,5,7,23]
     输出：true
     解释：挑选数字 5 和 7。
     5*3 + 7*(-2) = 1
     */
    nums = {12,5,7,23};
    res = true;
    assert(res == Solution().isGoodArray(nums));
    
    /**
     输入：nums = [29,6,10]
     输出：true
     解释：挑选数字 29, 6 和 10。
     29*1 + 6*(-3) + 10*(-1) = 1
     */
    nums = {29,6,10};
    res = true;
    assert(res == Solution().isGoodArray(nums));
    
    /**
     输入：nums = [3,6]
     输出：false
     */
    nums = {3,6};
    res = false;
    assert(res == Solution().isGoodArray(nums));

    cout << "OK~" << endl;
    
    return 0;
}
