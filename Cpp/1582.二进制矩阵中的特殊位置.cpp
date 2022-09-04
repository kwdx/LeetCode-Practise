/*
 * @lc app=leetcode.cn id=1582 lang=cpp
 *
 * [1582] 二进制矩阵中的特殊位置
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int m = (int)mat.size(), n = (int)mat[0].size();
        vector<int> r(m), c(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                r[i] += mat[i][j];
                c[j] += mat[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && r[i] == 1 && c[j] == 1) {
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
    
    vector<vector<int>> mat;
    int res;
    
    /**
     输入：mat = [[1,0,0],
                 [0,0,1],
                 [1,0,0]]
     输出：1
     解释：(1,2) 是一个特殊位置，因为 mat[1][2] == 1 且所处的行和列上所有其他元素都是 0
     */
    mat = {{1,0,0},{0,0,1},{1,0,0}};
    res = 1;
    assert(res == Solution().numSpecial(mat));
    
    /**
     输入：mat = [[1,0,0],
                 [0,1,0],
                 [0,0,1]]
     输出：3
     解释：(0,0), (1,1) 和 (2,2) 都是特殊位置
     */
    mat = {{1,0,0},{0,1,0},{0,0,1}};
    res = 3;
    assert(res == Solution().numSpecial(mat));
    
    /**
     输入：mat = [[0,0,0,1],
                 [1,0,0,0],
                 [0,1,1,0],
                 [0,0,0,0]]
     输出：2
     */
    mat = {{0,0,0,1},{1,0,0,0},{0,1,1,0},{0,0,0,0}};
    res = 2;
    assert(res == Solution().numSpecial(mat));
    
    /**
     输入：mat = [[0,0,0,0,0],
                 [1,0,0,0,0],
                 [0,1,0,0,0],
                 [0,0,1,0,0],
                 [0,0,0,1,1]]
     输出：3
     */
    mat = {{0,0,0,0,0},{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1}};
    res = 3;
    assert(res == Solution().numSpecial(mat));

    cout << "OK~" << endl;
    
    return 0;
}
