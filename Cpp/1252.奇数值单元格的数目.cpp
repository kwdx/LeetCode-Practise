/*
 * @lc app=leetcode.cn id=1252 lang=cpp
 *
 * [1252] 奇数值单元格的数目
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for (auto indice : indices) {
            rows[indice[0]] += 1;
            cols[indice[1]] += 1;
        }
        int ans = 0;
        for (int row : rows) {
            for (int col : cols) {
                if ((col + row) & 1) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int m;
    int n;
    vector<vector<int>> indices;
    int res;
    
    /**
     输入：m = 2, n = 3, indices = [[0,1],[1,1]]
     输出：6
     解释：最开始的矩阵是 [[0,0,0],[0,0,0]]。
     第一次增量操作后得到 [[1,2,1],[0,1,0]]。
     最后的矩阵是 [[1,3,1],[1,3,1]]，里面有 6 个奇数。
     */
    m = 2;
    n = 3;
    indices = {{0,1},{1,1}};
    res = 6;
    assert(res == Solution().oddCells(m, n, indices));
    
    /**
     输入：m = 2, n = 2, indices = [[1,1],[0,0]]
     输出：0
     解释：最后的矩阵是 [[2,2],[2,2]]，里面没有奇数。
     */
    
    m = 2;
    n = 2;
    indices = {{1,1},{0,0}};
    res = 0;
    assert(res == Solution().oddCells(m, n, indices));
    
    cout << "OK~" << endl;
    
    return 0;
}
