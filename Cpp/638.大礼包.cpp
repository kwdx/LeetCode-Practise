/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        _price = price;
        _special = special;
        n = (int)needs.size();
        return dfs(needs);
    }
    
private:
    vector<int> _price;
    vector<vector<int>> _special;
    int n;
    map<vector<int>, int> dp;

    int dfs(vector<int> needs) {
        if (dp.count(needs)) return dp[needs];

        int minVal = 0;
        for (int i = 0; i < needs.size(); i++)
            minVal += needs[i] * _price[i];

        for (int i = 0; i < _special.size(); i++) {
            vector<int> nextNeeds = needs;
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (_special[i][j] > nextNeeds[j])
                    flag = false;
                nextNeeds[j] -= _special[i][j];
            }
            if (!flag) continue;
            minVal = min(minVal, dfs(nextNeeds) + _special[i][n]);
        }
        return dp[needs] = minVal;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> price, needs;
    vector<vector<int>> special;
    int res;
    
    /**
     输入：price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
     输出：14
     解释：有 A 和 B 两种物品，价格分别为 ¥2 和 ¥5 。
     大礼包 1 ，你可以以 ¥5 的价格购买 3A 和 0B 。
     大礼包 2 ，你可以以 ¥10 的价格购买 1A 和 2B 。
     需要购买 3 个 A 和 2 个 B ， 所以付 ¥10 购买 1A 和 2B（大礼包 2），以及 ¥4 购买 2A 。
     */
    price = {2,5};
    special = {
        {3,0,5},
        {1,2,10}
    };
    needs = {3,2};
    res = 14;
    assert(res == Solution().shoppingOffers(price, special, needs));
    
    /**
     输入：price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
     输出：11
     解释：A ，B ，C 的价格分别为 ¥2 ，¥3 ，¥4 。
     可以用 ¥4 购买 1A 和 1B ，也可以用 ¥9 购买 2A ，2B 和 1C 。
     需要买 1A ，2B 和 1C ，所以付 ¥4 买 1A 和 1B（大礼包 1），以及 ¥3 购买 1B ， ¥4 购买 1C 。
     不可以购买超出待购清单的物品，尽管购买大礼包 2 更加便宜。

     */
    price = {2,3,4};
    special = {
        {1,1,0,4},
        {2,2,1,9}
    };
    needs = {1,2,1};
    res = 11;
    assert(res == Solution().shoppingOffers(price, special, needs));
    
    cout << "OK~" << endl;
    
    return 0;
}
