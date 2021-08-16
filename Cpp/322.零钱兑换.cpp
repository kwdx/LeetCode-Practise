/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    int getCoins(vector<int>& faces, int dp[], int n) {
        if (n < 0) return -1;
        if (n == 0) return 0;
        if (dp[n] == 0) {
            int coin = -1;
            for (auto face : faces) {
                int val = getCoins(faces, dp, n - face);
                if (val >= 0) {
                    if (coin != -1) coin = min(coin, val + 1);
                    else coin = val + 1;
                }
            }
            dp[n] = coin;
        }
        return dp[n];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        memset(dp, 0, (amount + 1) * sizeof(int));
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] == amount) return 1;
            if (coins[i] < amount) dp[coins[i]] = 1;
        }
        
        return getCoins(coins, dp, amount);
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...

    vector<int> coins;
    
    coins = {1,2,5};
    // 3
    cout << Solution().coinChange(coins, 11) << endl;

    coins = {2};
    // -1
    cout << Solution().coinChange(coins, 3) << endl;
    
    coins = {1};
    // 0
    cout << Solution().coinChange(coins, 0) << endl;
    
    coins = {1};
    // 1
    cout << Solution().coinChange(coins, 1) << endl;
    
    coins = {1};
    // 2
    cout << Solution().coinChange(coins, 2) << endl;

    return 0;
}
