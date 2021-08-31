/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0 = 0, dp_1 = INT_MIN;
        int pre_dp_0 = 0;
        for (int price : prices) {
            int temp = dp_0;
            dp_0 = max(dp_0, dp_1 + price);
            dp_1 = max(dp_1, pre_dp_0 - price);
            pre_dp_0 = temp;
        }
        return dp_0;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> prices;
    int res;

    /**
     输入: [1,2,3,0,2]
     输出: 3
     解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
     */
    prices = {1,2,3,0,2};
    res = 3;
    assert(res == Solution().maxProfit(prices));

    cout << "OK~" << endl;

    return 0;
}
