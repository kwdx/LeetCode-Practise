/*
 * @lc app=leetcode.cn id=zero-matrix-lcci lang=cpp
 *
 * [面试题] 01.08. 零矩阵
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!matrix[i][j]) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> matrix;
    vector<vector<int>> res;
    
    /**
     输入：
     [
       [1,1,1],
       [1,0,1],
       [1,1,1]
     ]
     输出：
     [
       [1,0,1],
       [0,0,0],
       [1,0,1]
     ]
     */
    matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    res = {
        {1,0,1},
        {0,0,0},
        {1,0,1}
    };
    Solution().setZeroes(matrix);
    assert(res == matrix);
    
    /**
     输入：
     [
       [0,1,2,0],
       [3,4,5,2],
       [1,3,1,5]
     ]
     输出：
     [
       [0,0,0,0],
       [0,4,5,0],
       [0,3,1,0]
     ]
     */
    matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    res = {
        {0,0,0,0},
        {0,4,5,0},
        {0,3,1,0}
    };
    Solution().setZeroes(matrix);
    assert(res == matrix);

    cout << "OK~" << endl;
    
    return 0;
}
