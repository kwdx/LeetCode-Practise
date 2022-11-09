/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int>(n, n));
        unordered_set<int> banned;
        for (auto&& vec : mines) {
            banned.emplace(vec[0] * n + vec[1]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            // left
            for (int j = 0; j < n; ++j) {
                if (banned.count(i * n + j)) {
                    count = 0;
                } else {
                    ++count;
                }
                dp[i][j] = min(dp[i][j], count);
            }
            count = 0;
            // right
            for (int j = n - 1; j >= 0; --j) {
                if (banned.count(i * n + j)) {
                    count = 0;
                } else {
                    ++count;
                }
                dp[i][j] = min(dp[i][j], count);
            }
        }
        for (int i = 0; i < n; ++i) {
            int count = 0;
            // up
            for (int j = 0; j < n; ++j) {
                if (banned.count(j * n + i)) {
                    count = 0;
                } else {
                    ++count;
                }
                dp[j][i] = min(dp[j][i], count);
            }
            count = 0;
            // down
            for (int j = n - 1; j >= 0; --j) {
                if (banned.count(j * n + i)) {
                    count = 0;
                } else {
                    ++count;
                }
                dp[j][i] = min(dp[j][i], count);
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    vector<vector<int>> mines;
    int res;
    
    /**
     输入: n = 5, mines = [[4, 2]]
     输出: 2
     解释: 在上面的网格中，最大加号标志的阶只能是2。一个标志已在图中标出。
     */
    n = 5;
    mines = {{4,2}};
    res = 2;
    assert(res == Solution().orderOfLargestPlusSign(n, mines));
    
    /**
     输入: n = 1, mines = [[0, 0]]
     输出: 0
     解释: 没有加号标志，返回 0 。
     */
    n = 1;
    mines = {{0,0}};
    res = 0;
    assert(res == Solution().orderOfLargestPlusSign(n, mines));
    
    cout << "OK~" << endl;
    
    return 0;
}
