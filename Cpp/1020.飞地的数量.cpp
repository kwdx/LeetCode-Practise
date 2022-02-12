/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int m = (int)grid.size(), n = (int)grid[0].size();
        deque<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!(i == 0 or i == m - 1 or j == 0 or j == n - 1)) {
                    continue;
                }
                if (grid[i][j] == 0) {
                    continue;
                }
                grid[i][j] = 0;
                q.push_back({i,j});
                while (!q.empty()) {
                    auto cell = q.front();
                    q.pop_front();
                    for (auto& dir : dirs) {
                        int x = cell.first + dir.first;
                        int y = cell.second + dir.second;
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                            grid[x][y] = 0;
                            q.push_back({x,y});
                        }
                    }
                }
            }
        }
//        }
//        auto bfs = [&q, dirs, m, n, &grid]() {
//            while (!q.empty()) {
//                auto cell = q.front();
//                for (pair<int, int> dir : dirs) {
//                    int x = cell.first + dir.first, y = cell.second + dir.second;
//                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
//                        grid[x][y] = 0;
//                        q.push_back({x, y});
//                    }
//                }
//            }
//        };
//        for (int i = 0; i < m; ++i) {
//            if (grid[i][0] == 1) q.push_back({i, 0});
//            if (grid[i][n - 1] == 1) q.push_back({i, n - 1});
//            bfs();
//        }
//        for (int i = 0; i < n; ++i) {
//            if (grid[0][i] == 1) q.push_back({0, i});
//            if (grid[m - 1][i] == 1) q.push_back({m - 1, i});
//            bfs();
//        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> grid;
    int res;
    
    /**
     输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
     输出：3
     解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
     */
    grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    res = 3;
    assert(res == Solution().numEnclaves(grid));
    
    /**
     输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
     输出：0
     解释：所有 1 都在边界上或可以到达边界。
     */
    grid = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
    res = 0;
    assert(res == Solution().numEnclaves(grid));

    cout << "OK~" << endl;

    return 0;
}
