/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // if (k == 2) return maxProfitLimit2(prices);
        int n = (int)prices.size();

        if (k > (n >> 1)) return maxProfitWithoutLimit(prices);

        int dp[k + 1][2];
        for (int i = 0; i <= k; i++) {
            dp[i][0] = 0;
            dp[i][1] = INT_MIN;
        }

        for (int i = 0; i < n; i++) {
            for (int j = k; j >= 1; j--) {
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
                dp[j][1] = max(dp[j][1], dp[j-1][0] - prices[i]);
            }
        }
        return dp[k][0];
    }

    int maxProfitWithoutLimit(vector<int>& prices) {
        int dp_0 = 0, dp_1 = INT_MIN;
        for (int price : prices) {
            dp_0 = max(dp_0, dp_1 + price);
            dp_1 = max(dp_1, dp_0 - price);
        }
        return dp_0;
    }

//    int maxProfitLimit2(vector<int>& prices) {
//        int dp_1_0 = 0, dp_1_1 = INT_MIN;
//        int dp_2_0 = 0, dp_2_1 = INT_MIN;
//        for (int price : prices) {
//            dp_2_0 = max(dp_2_0, dp_2_1 + price);
//            dp_2_1 = max(dp_2_1, dp_1_0 - price);
//
//            dp_1_0 = max(dp_1_0, dp_1_1 + price);
//            dp_1_1 = max(dp_1_1, dp_1_0 - price);
//        }
//        return dp_2_0;
//    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> prices;
    int k, res;

    /**
     输入：k = 2, prices = [2,4,1]
     输出：2
     解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
     */
    prices = {2,4,1};
    k = 2;
    res = 2;
    assert(res == Solution().maxProfit(k, prices));

    /**
     输入：k = 2, prices = [3,2,6,5,0,3]
     输出：7
     解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
          随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
     */
    prices = {3,2,6,5,0,3};
    k = 2;
    res = 7;
    assert(res == Solution().maxProfit(k, prices));

    cout << "OK~" << endl;

    return 0;
}
