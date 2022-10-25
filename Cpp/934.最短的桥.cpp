/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        vector<pair<int, int>> island;
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.emplace(i, j);
                    grid[i][j] = -1;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        island.emplace_back(x, y);
                        for (auto dir : dirs) {
                            int nx = x + dir[0];
                            int ny = y + dir[1];
                            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1) {
                                q.emplace(nx, ny);
                                grid[nx][ny] = -1;
                            }
                        }
                    }
                    for (auto &&[x, y] : island) {
                        q.emplace(x, y);
                    }
                    int step = 0;
                    while (!q.empty()) {
                        int sz = (int)q.size();
                        for (int i = 0; i < sz; ++i) {
                            auto [x, y] = q.front();
                            q.pop();
                            for (auto &dir : dirs) {
                                int nx = x + dir[0];
                                int ny = y + dir[1];
                                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                                    if (grid[nx][ny] == 0) {
                                        q.emplace(nx, ny);
                                        grid[nx][ny] = -1;
                                    } else if (grid[nx][ny] == 1) {
                                        return step;
                                    }
                                }
                            }
                        }
                        ++step;
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> grid;
    int res;
    
    /**
     输入：grid = [[0,1],[1,0]]
     输出：1
     */
    grid = {{0,1},{1,0}};
    res = 1;
    assert(res == Solution().shortestBridge(grid));
    
    /**
     输入：grid = [[0,1,0],[0,0,0],[0,0,1]]
     输出：2
     */
    grid = {{0,1,0},{0,0,0},{0,0,1}};
    res = 2;
    assert(res == Solution().shortestBridge(grid));
    
    /**
     输入：grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
     输出：1
     */
    grid = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    res = 1;
    assert(res == Solution().shortestBridge(grid));
    
    cout << "OK~" << endl;
    
    return 0;
}
