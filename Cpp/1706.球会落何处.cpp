/*
 * @lc app=leetcode.cn id=1706 lang=cpp
 *
 * [1706] 球会落何处
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        vector<int> ans(n, 0);

        auto getVal = [grid, m, n](int x) {
            int row = 0, col = x;
            while (row < m) {
                int nextCol = col + grid[row][col];
                if (nextCol < 0 || nextCol >= n) return -1;
                if (grid[row][col] != grid[row][nextCol]) return -1;
                ++row;
                col = nextCol;
            }
            return col;
        };
        
        for (int i = 0; i < n; ++i)
            ans[i] = getVal(i);
        
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> grid;
    vector<int> res;
    
    /**
     输入：grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
     输出：[1,-1,-1,-1,-1]
     解释：示例如图：
     b0 球开始放在第 0 列上，最终从箱子底部第 1 列掉出。
     b1 球开始放在第 1 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
     b2 球开始放在第 2 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
     b3 球开始放在第 3 列上，会卡在第 2、3 列和第 0 行之间的 "V" 形里。
     b4 球开始放在第 4 列上，会卡在第 2、3 列和第 1 行之间的 "V" 形里。
     */
    grid = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    res = {1,-1,-1,-1,-1};
    assert(res == Solution().findBall(grid));
    
    /**
     输入：grid = [[-1]]
     输出：[-1]
     解释：球被卡在箱子左侧边上。
     */
    grid = {{-1}};
    res = {-1};
    assert(res == Solution().findBall(grid));
    
    /**
     输入：grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
     输出：[0,1,2,3,4,-1]
     */
    grid = {{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1}};
    res = {0,1,2,3,4,-1};
    assert(res == Solution().findBall(grid));

    cout << "OK~" << endl;
    
    return 0;
}
