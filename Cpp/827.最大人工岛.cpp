/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// @lc code=start
const vector<int> d = {0, -1, 0, 1, 0};

class Solution {
public:
    bool valid(int n, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    int dfs(const vector<vector<int>> &grid, int x, int y, vector<vector<int>> &tag, int t) {
        int n = (int)grid.size(), res = 1;
        tag[x][y] = t;
        for (int i = 0; i < 4; i++) {
            int x1 = x + d[i], y1 = y + d[i + 1];
            if (valid(n, x1, y1) && grid[x1][y1] == 1 && tag[x1][y1] == 0) {
                res += dfs(grid, x1, y1, tag, t);
            }
        }
        return res;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = (int)grid.size(), res = 0;
        vector<vector<int>> tag(n, vector<int>(n));
        unordered_map<int, int> area;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && tag[i][j] == 0) {
                    int t = i * n + j + 1;
                    area[t] = dfs(grid, i, j, tag, t);
                    res = max(res, area[t]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int z = 1;
                    unordered_set<int> connected;
                    for (int k = 0; k < 4; k++) {
                        int x = i + d[k], y = j + d[k + 1];
                        if (!valid(n, x, y) || tag[x][y] == 0 || connected.count(tag[x][y]) > 0) {
                            continue;
                        }
                        z += area[tag[x][y]];
                        connected.insert(tag[x][y]);
                    }
                    res = max(res, z);
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> grid;
    int res;
    
    /**
     输入: grid = [[1, 0], [0, 1]]
     输出: 3
     解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
     */
    grid = {{1,0},{0,1}};
    res = 3;
    assert(res == Solution().largestIsland(grid));
    
    /**
     输入: grid = [[1, 1], [1, 0]]
     输出: 4
     解释: 将一格0变成1，岛屿的面积扩大为 4。
     */
    grid = {{1,1},{1,0}};
    res = 4;
    assert(res == Solution().largestIsland(grid));
    
    /**
     输入: grid = [[1, 1], [1, 1]]
     输出: 4
     解释: 没有0可以让我们变成1，面积依然为 4。
     */
    grid = {{1,1},{1,1}};
    res = 4;
    assert(res == Solution().largestIsland(grid));

    cout << "OK~" << endl;
    
    return 0;
}
