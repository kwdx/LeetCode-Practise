/*
 * @lc app=leetcode.cn id=1814 lang=cpp
 *
 * [1814] 统计一个数组中好对子的数目
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int ans = 0;
        unordered_map<int, int> h;
        for (int i : nums) {
            int temp = i, j = 0;
            while (temp > 0) {
                j = j * 10 + temp % 10;
                temp /= 10;
            }
            ans = (ans + h[i - j]) % MOD;
            h[i - j]++;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;

    /**
     输入：nums = [42,11,1,97]
     输出：2
     解释：两个坐标对为：
      - (0,3)：42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121 。
      - (1,2)：11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12 。
     */
    nums = {42,11,1,97};
    res = 2;
    assert(res == Solution().countNicePairs(nums));
    
    /**
     输入：nums = [13,10,35,24,76]
     输出：4
     */
    nums = {13,10,35,24,76};
    res = 4;
    assert(res == Solution().countNicePairs(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
