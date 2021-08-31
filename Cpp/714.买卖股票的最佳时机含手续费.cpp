/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp_0 = 0, dp_1 = INT_MIN;
        for (int price : prices) {
            dp_0 = max(dp_0, dp_1 + price);
            dp_1 = max(dp_1, dp_0 - fee - price);
        }
        return dp_0;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> prices;
    int fee, res;

    /**
     输入：prices = [1,3,2,8,4,9], fee = 2
     输出：8
     解释：能够达到的最大利润:
     在此处买入 prices[0] = 1
     在此处卖出 prices[3] = 8
     在此处买入 prices[4] = 4
     在此处卖出 prices[5] = 9
     总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8
     */
    prices = {1,3,2,8,4,9};
    fee = 2;
    res = 8;
    assert(res == Solution().maxProfit(prices, fee));

    /**
     输入：prices = [1,3,7,5,10,3], fee = 3
     输出：6
     */
    prices = {1,3,7,5,10,3};
    fee = 3;
    res = 6;
    assert(res == Solution().maxProfit(prices, fee));

    cout << "OK~" << endl;

    return 0;
}
