/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i] = max(rows[i], grid[i][j]);
                cols[j] = max(cols[j], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += min(rows[i], cols[j]) - grid[i][j];
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
     输入： grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
     输出： 35
     解释：
     The grid is:
     [ [3, 0, 8, 4],
       [2, 4, 5, 7],
       [9, 2, 6, 3],
       [0, 3, 1, 0] ]

     从数组竖直方向（即顶部，底部）看“天际线”是：[9, 4, 8, 7]
     从水平水平方向（即左侧，右侧）看“天际线”是：[8, 7, 9, 3]

     在不影响天际线的情况下对建筑物进行增高后，新数组如下：

     gridNew = [ [8, 4, 8, 7],
                 [7, 4, 7, 7],
                 [9, 4, 8, 7],
                 [3, 3, 3, 3] ]
     */
    grid = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    res = 35;
    assert(res == Solution().maxIncreaseKeepingSkyline(grid));

    cout << "OK~" << endl;

    return 0;
}
