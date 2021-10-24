/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int first = 0;  // 上上家
        int second = 0; // 上一家
        int tmp;
        for (int num : nums) {
            tmp = second;
            first += num;
            second = first > second ? first : second;
            first = tmp;
        }
        return first > second ? first : second;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入：[1,2,3,1]
     输出：4
     解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
          偷窃到的最高金额 = 1 + 3 = 4 。
     */
    nums = {1,2,3,1};
    res = 4;
    assert(res == Solution().rob(nums));
    
    /**
     输入：[2,7,9,3,1]
     输出：12
     解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
          偷窃到的最高金额 = 2 + 9 + 1 = 12 。
     */
    nums = {2,7,9,3,1};
    res = 12;
    assert(res == Solution().rob(nums));

    cout << "OK~" << endl;
    
    return 0;
}
