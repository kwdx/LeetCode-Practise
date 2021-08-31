/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0 = 0, dp_1 = INT_MIN;
        for (int price : prices) {
            dp_0 = max(dp_0, dp_1 + price);
            dp_1 = max(dp_1, -price);
        }
        return dp_0;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> prices;
    int res;

    /**
     输入：[7,1,5,3,6,4]
     输出：5
     解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
          注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
     */
    prices = {7,1,5,3,6,4};
    res = 5;
    assert(res == Solution().maxProfit(prices));

    /**
     输入：prices = [7,6,4,3,1]
     输出：0
     解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
     */
    prices = {7,6,4,3,1};
    res = 0;
    assert(res == Solution().maxProfit(prices));

    cout << "OK~" << endl;

    return 0;
}
