/*
 * @lc app=leetcode.cn id=1765 lang=cpp
 *
 * [1765] 地图中的最高点
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
private:
    const int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = (int)isWater.size(), m = (int)isWater[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isWater[i][j] == 1) {
                    q.emplace(i, j);
                } else {
                    ans[i][j] = -1;
                }
            }
        }
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int a = x + direction[i][0];
                int b = y + direction[i][1];
                if (a < 0 || a == n || b < 0 || b == m) continue;
                if (ans[a][b] >= 0) continue;
                ans[a][b] = ans[x][y] + 1;
                q.emplace(a, b);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> isWater;
    vector<vector<int>> res;
    
    /**
     输入：isWater = [[0,1],[0,0]]
     输出：[[1,0],[2,1]]
     解释：上图展示了给各个格子安排的高度。
     蓝色格子是水域格，绿色格子是陆地格。
     */
    isWater = {{0,1},{0,0}};
    res = {{1,0},{2,1}};
    assert(res == Solution().highestPeak(isWater));
    
    /**
     输入：isWater = [[0,0,1],[1,0,0],[0,0,0]]
     输出：[[1,1,0],[0,1,1],[1,2,2]]
     解释：所有安排方案中，最高可行高度为 2 。
     任意安排方案中，只要最高高度为 2 且符合上述规则的，都为可行方案。
     */
    isWater = {{0,0,1},{1,0,0},{0,0,0}};
    res = {{1,1,0},{0,1,1},{1,2,2}};
    assert(res == Solution().highestPeak(isWater));

    cout << "OK~" << endl;

    return 0;
}

