/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 *
 * [1260] 二维网格迁移
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        vector<vector<int>> ans = grid;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = (i * n + j + k) % (m * n);
                int x = idx / n, y = idx % n;
                ans[x][y] = grid[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> grid;
    int k;
    vector<vector<int>> res;
    
    /**
     输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
     输出：[[9,1,2],[3,4,5],[6,7,8]]
     */
    grid = {{1,2,3},{4,5,6},{7,8,9}};
    k = 1;
    res = {{9,1,2},{3,4,5},{6,7,8}};
    assert(res == Solution().shiftGrid(grid, k));
    
    /**
     输入：grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
     输出：[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
     */
    grid = {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}};
    k = 4;
    res = {{12,0,21,13},{3,8,1,9},{19,7,2,5},{4,6,11,10}};
    assert(res == Solution().shiftGrid(grid, k));
    
    /**
     输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
     输出：[[1,2,3],[4,5,6],[7,8,9]]
     */
    grid = {{1,2,3},{4,5,6},{7,8,9}};
    k = 9;
    res = {{1,2,3},{4,5,6},{7,8,9}};
    assert(res == Solution().shiftGrid(grid, k));

    cout << "OK~" << endl;
    
    return 0;
}
