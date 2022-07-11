/*
 * @lc app=leetcode.cn id=741 lang=cpp
 *
 * [741] 摘樱桃
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        vector<vector<int>> f(n, vector<int>(n, INT_MIN));
        f[0][0] = grid[0][0];
        
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int x1 = min(k, n - 1); x1 >= max(k - n + 1, 0); --x1) {
                for (int x2 = min(k, n - 1); x2 >= x1; --x2) {
                    int y1 = k - x1, y2 = k - x2;
                    if (grid[x1][y1] == -1 || grid[x2][y2] == -1) {
                        f[x1][x2] = INT_MIN;
                        continue;
                    }
                    int ans = f[x1][x2]; // 都往右
                    if (x1) {
                        ans = max(ans, f[x1 - 1][x2]); // 往下，往右
                    }
                    if (x2) {
                        ans = max(ans, f[x1][x2 - 1]); // 往右，往下
                    }
                    if (x1 && x2) {
                        ans = max(ans, f[x1 - 1][x2 - 1]); // 都往下
                    }
                    ans += grid[x1][y1];
                    if (x2 != x1) { // 避免重复摘同一个樱桃
                        ans += grid[x2][y2];
                    }
                    f[x1][x2] = ans;
                }
            }
        }
        return max(f.back().back(), 0);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> grid;
    int res;
    
    /**
     输入: grid =
     [[0, 1, -1],
      [1, 0, -1],
      [1, 1,  1]]
     输出: 5
     解释：
     玩家从（0,0）点出发，经过了向下走，向下走，向右走，向右走，到达了点(2, 2)。
     在这趟单程中，总共摘到了4颗樱桃，矩阵变成了[[0,1,-1],[0,0,-1],[0,0,0]]。
     接着，这名玩家向左走，向上走，向上走，向左走，返回了起始点，又摘到了1颗樱桃。
     在旅程中，总共摘到了5颗樱桃，这是可以摘到的最大值了。
     */
    grid = {
        {0, 1, -1},
        {1, 0, -1},
        {1, 1, 1}
    };
    res = 5;
    assert(res == Solution().cherryPickup(grid));
    
    cout << "OK~" << endl;
    
    return 0;
}
