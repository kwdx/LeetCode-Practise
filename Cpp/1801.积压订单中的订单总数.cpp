/*
 * @lc app=leetcode.cn id=1801 lang=cpp
 *
 * [1801] 积压订单中的订单总数
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const int MOD = 1000000007;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> buyOrders;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sellOrders;
        for (auto &&order : orders) {
            int price = order[0], amount = order[1], orderType = order[2];
            if (orderType == 0) {
                while (amount > 0 && !sellOrders.empty() && sellOrders.top().first <= price) {
                    auto sellOrder = sellOrders.top();
                    sellOrders.pop();
                    int sellAmount = min(amount, sellOrder.second);
                    amount -= sellAmount;
                    sellOrder.second -= sellAmount;
                    if (sellOrder.second > 0) {
                        sellOrders.push(sellOrder);
                    }
                }
                if (amount > 0) {
                    buyOrders.emplace(price, amount);
                }
            } else {
                while (amount > 0 && !buyOrders.empty() && buyOrders.top().first >= price) {
                    auto buyOrder = buyOrders.top();
                    buyOrders.pop();
                    int buyAmount = min(amount, buyOrder.second);
                    amount -= buyAmount;
                    buyOrder.second -= buyAmount;
                    if (buyOrder.second > 0) {
                        buyOrders.push(buyOrder);
                    }
                }
                if (amount > 0) {
                    sellOrders.emplace(price, amount);
                }
            }
        }
        int total = 0;
        while (!buyOrders.empty()) {
            total = (total + buyOrders.top().second) % MOD;
            buyOrders.pop();
        }
        while (!sellOrders.empty()) {
            total = (total + sellOrders.top().second) % MOD;
            sellOrders.pop();
        }
        return total;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> orders;
    int res;
    
    /**
     输入：orders = [[10,5,0],[15,2,1],[25,1,1],[30,4,0]]
     输出：6
     解释：输入订单后会发生下述情况：
     - 提交 5 笔采购订单，价格为 10 。没有销售订单，所以这 5 笔订单添加到积压订单中。
     - 提交 2 笔销售订单，价格为 15 。没有采购订单的价格大于或等于 15 ，所以这 2 笔订单添加到积压订单中。
     - 提交 1 笔销售订单，价格为 25 。没有采购订单的价格大于或等于 25 ，所以这 1 笔订单添加到积压订单中。
     - 提交 4 笔采购订单，价格为 30 。前 2 笔采购订单与价格最低（价格为 15）的 2 笔销售订单匹配，从积压订单中删除这 2 笔销售订单。第 3 笔采购订单与价格最低的 1 笔销售订单匹配，销售订单价格为 25 ，从积压订单中删除这 1 笔销售订单。积压订单中不存在更多销售订单，所以第 4 笔采购订单需要添加到积压订单中。
     最终，积压订单中有 5 笔价格为 10 的采购订单，和 1 笔价格为 30 的采购订单。所以积压订单中的订单总数为 6 。
     */
    orders = {{10,5,0},{15,2,1},{25,1,1},{30,4,0}};
    res = 6;
    assert(res == Solution().getNumberOfBacklogOrders(orders));
    
    /**
     输入：orders = [[7,1000000000,1],[15,3,0],[5,999999995,0],[5,1,1]]
     输出：999999984
     解释：输入订单后会发生下述情况：
     - 提交 109 笔销售订单，价格为 7 。没有采购订单，所以这 109 笔订单添加到积压订单中。
     - 提交 3 笔采购订单，价格为 15 。这些采购订单与价格最低（价格为 7 ）的 3 笔销售订单匹配，从积压订单中删除这 3 笔销售订单。
     - 提交 999999995 笔采购订单，价格为 5 。销售订单的最低价为 7 ，所以这 999999995 笔订单添加到积压订单中。
     - 提交 1 笔销售订单，价格为 5 。这笔销售订单与价格最高（价格为 5 ）的 1 笔采购订单匹配，从积压订单中删除这 1 笔采购订单。
     最终，积压订单中有 (1000000000-3) 笔价格为 7 的销售订单，和 (999999995-1) 笔价格为 5 的采购订单。所以积压订单中的订单总数为 1999999991 ，等于 999999984 % (109 + 7) 。
     */
    orders = {{7,1000000000,1},{15,3,0},{5,999999995,0},{5,1,1}};
    res = 999999984;
    assert(res == Solution().getNumberOfBacklogOrders(orders));
    
    cout << "OK~" << endl;
    
    return 0;
}
