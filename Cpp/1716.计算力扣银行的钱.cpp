/*
 * @lc app=leetcode.cn id=1716 lang=cpp
 *
 * [1716] 计算力扣银行的钱
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        int monday = 1;
        int ans = 0;
        while (weeks-- > 0) {
            ans += (monday + monday + 6) * 7 / 2;
            ++monday;
        }
        while (days-- > 0) {
            ans += monday++;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int res;
    
    /**
     输入：n = 4
     输出：10
     解释：第 4 天后，总额为 1 + 2 + 3 + 4 = 10 。
     */
    n = 4;
    res = 10;
    assert(res == Solution().totalMoney(n));
    
    /**
     输入：n = 10
     输出：37
     解释：第 10 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37 。注意到第二个星期一，Hercy 存入 2 块钱。
     */
    n = 10;
    res = 37;
    assert(res == Solution().totalMoney(n));
    
    /**
     输入：n = 20
     输出：96
     解释：第 20 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96 。
     */
    n = 20;
    res = 96;
    assert(res == Solution().totalMoney(n));

    cout << "OK~" << endl;

    return 0;
}

