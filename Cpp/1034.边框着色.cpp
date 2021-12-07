/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边框着色
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    int m = 0, n = 0;
    vector<vector<bool>> visited;
    vector<pair<int, int>> borders;

    void dfs(vector<vector<int>>& grid, int x, int y, int originalColor) {
        bool isBorder = false;
        // 4个方向
        int direc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < 4; i++) {
            int nx = direc[i][0] + x, ny = direc[i][1] + y;
            if (!(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == originalColor)) {
                isBorder = true;
            } else if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                dfs(grid, nx, ny, originalColor);
            }
        }
        if (isBorder) {
            borders.emplace_back(x, y);
        }
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = (int)grid.size();
        n = (int)grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        int originalColor = grid[row][col];
        visited[row][col] = true;
        dfs(grid, row, col, originalColor);
        for (auto & [x, y] : borders) {
            grid[x][y] = color;
        }
        return grid;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> grid;
    int row, col, color;
    vector<vector<int>> res;
    
    /**
     输入：grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
     输出：[[3,3],[3,2]]
     */
    grid = {{1,1},{1,2}};
    row = 0;
    col = 0;
    color = 3;
    res = {{3,3},{3,2}};
    assert(res == Solution().colorBorder(grid, row, col, color));
    
    /**
     输入：grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
     输出：[[1,3,3],[2,3,3]]
     */
    grid = {{1,2,2},{2,3,2}};
    row = 0;
    col = 1;
    color = 3;
    res = {{1,3,3},{2,3,3}};
    assert(res == Solution().colorBorder(grid, row, col, color));
    
    /**
     输入：grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
     输出：[[2,2,2],[2,1,2],[2,2,2]]
     */
    grid = {{1,1,1},{1,1,1},{1,1,1}};
    row = 1;
    col = 1;
    color = 2;
    res = {{2,2,2},{2,1,2},{2,2,2}};
    assert(res == Solution().colorBorder(grid, row, col, color));

    cout << "OK~" << endl;

    return 0;
}
