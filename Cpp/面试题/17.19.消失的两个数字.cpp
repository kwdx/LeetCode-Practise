/*
 * @lc app=leetcode.cn id=missing-two-lcci lang=cpp
 *
 * [面试题] 17.19.消失的两个数字
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = (int)nums.size() + 2;
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int x = (1 + n) * n / 2 - sum;
        int half = x / 2;
        
        int ans = (1 + half) * half / 2;
        for (int num : nums) {
            if (num <= half) {
                ans -= num;
            }
        }
        
        return {ans, x - ans};
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    vector<int> res;
    
    /**
     输入: [1]
     输出: [2,3]
     */
    nums = {1};
    res = {2,3};
    assert(res == Solution().missingTwo(nums));
    
    /**
     输入: [2,3]
     输出: [1,4]
     */
    nums = {2,3};
    res = {1,4};
    assert(res == Solution().missingTwo(nums));

    cout << "OK~" << endl;
    
    return 0;
}

