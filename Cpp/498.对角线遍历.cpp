/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = (int)mat.size(), n = (int)mat[0].size(), cnt = m * n;
        int x = 0, y = 0, dir = 1, idx = 0;
        
        vector<int> ans(cnt);
        while (idx != cnt) {
            ans[idx++] = mat[x][y];
            int nx = x, ny = y;
            if (dir == 1) {
                // 往左下走
                nx = x - 1;
                ny = y + 1;
            } else {
                // 往右上走
                nx = x + 1;
                ny = y - 1;
            }
            if (idx < cnt && (nx < 0 || nx >= m || ny < 0 || ny >= n)) {
                if (dir == 1) {
                    nx = y + 1 < n ? x : x + 1;
                    ny = y + 1 < n ? y + 1 : y;
                } else {
                    nx = x + 1 < m ? x + 1 : x;
                    ny = x + 1 < m ? y : y + 1;
                }
                dir = -dir;
            }
            x = nx;
            y = ny;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> mat;
    vector<int> res;
    
    /**
     输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
     输出：[1,2,4,7,5,3,6,8,9]
     */
    mat = {{1,2,3},{4,5,6},{7,8,9}};
    res = {1,2,4,7,5,3,6,8,9};
    assert(res == Solution().findDiagonalOrder(mat));
    
    /**
     输入：mat = [[1,2],[3,4]]
     输出：[1,2,3,4]
     */
    mat = {{1,2},{3,4}};
    res = {1,2,3,4};
    assert(res == Solution().findDiagonalOrder(mat));
    
    cout << "OK~" << endl;
    
    return 0;
}
