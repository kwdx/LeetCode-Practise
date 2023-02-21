/*
 * @lc app=leetcode.cn id=1139 lang=cpp
 *
 * [1139] 最大的以 1 为边界的正方形
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        vector<vector<int>> left(m + 1, vector<int>(n + 1));
        vector<vector<int>> up(m + 1, vector<int>(n + 1));
        int maxLen = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (grid[i - 1][j - 1] == 1) {
                    left[i][j] = left[i][j - 1] + 1;
                    up[i][j] = up[i - 1][j] + 1;
                    int len = min(left[i][j], up[i][j]);
                    while (left[i - len + 1][j] < len || up[i][j - len + 1] < len) {
                        --len;
                    }
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen * maxLen;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> grid;
    int res;
    
    /**
     输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
     输出：9
     */
    grid = {{1,1,1},{1,0,1},{1,1,1}};
    res = 9;
    assert(res == Solution().largest1BorderedSquare(grid));
    
    /**
     输入：grid = [[1,1,0,0]]
     输出：1
     */
    grid = {{1,1,0,0}};
    res = 1;
    assert(res == Solution().largest1BorderedSquare(grid));

    cout << "OK~" << endl;
    
    return 0;
}
