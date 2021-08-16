/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int dp1 = 1, dp2 = 1;
        for (int i = 2; i <= n; i++) {
        int tmp = dp2;
            dp2 = dp1 + dp2;
            dp1 = tmp;
        }
        return dp2;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;
    // 2
    cout << solution.climbStairs(2) << endl;
    // 3
    cout << solution.climbStairs(3) << endl;
    return 0;
}
