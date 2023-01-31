/*
 * @lc app=leetcode.cn id=2319 lang=cpp
 *
 * [2319] 判断矩阵是否是一个 X 矩阵
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || i == n - j - 1) {
                    if (grid[i][j] == 0) {
                        return false;
                    }
                } else {
                    if (grid[i][j] != 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> grid;
    bool res;
    
    /**
     输入：grid = [[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]
     输出：true
     解释：矩阵如上图所示。
     X 矩阵应该满足：绿色元素（对角线上）都不是 0 ，红色元素都是 0 。
     因此，grid 是一个 X 矩阵。
     */
    grid = {{2,0,0,1},{0,3,1,0},{0,5,2,0},{4,0,0,2}};
    res = true;
    assert(res == Solution().checkXMatrix(grid));
    
    /**
     输入：grid = [[5,7,0],[0,3,1],[0,5,0]]
     输出：false
     解释：矩阵如上图所示。
     X 矩阵应该满足：绿色元素（对角线上）都不是 0 ，红色元素都是 0 。
     因此，grid 不是一个 X 矩阵。
     */
    grid = {{5,7,0},{0,3,1},{0,5,0}};
    res = false;
    assert(res == Solution().checkXMatrix(grid));

    cout << "OK~" << endl;
    
    return 0;
}
