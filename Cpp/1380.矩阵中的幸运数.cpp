/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = (int)matrix.size(), n = (int)matrix[0].size();
        vector<int> row(m), col(n);
        col = matrix[0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) row[i] = matrix[i][j];
                row[i] = min(row[i], matrix[i][j]);
                col[j] = max(col[j], matrix[i][j]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] == matrix[i][j] && col[j] == matrix[i][j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> matrix;
    vector<int> res;
    
    /**
     输入：matrix = [[3,7,8],[9,11,13],[15,16,17]]
     输出：[15]
     解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
     */
    matrix = {{3,7,8},{9,11,13},{15,16,17}};
    res = {15};
    assert(res == Solution().luckyNumbers(matrix));
    
    /**
     输入：matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
     输出：[12]
     解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
     */
    matrix = {{1,10,4,2},{9,3,8,7},{15,16,17,12}};
    res = {12};
    assert(res == Solution().luckyNumbers(matrix));
    
    /**
     输输入：matrix = [[7,8],[1,2]]
     输出：[7]
     */
    matrix = {{7,8},{1,2}};
    res = {7};
    assert(res == Solution().luckyNumbers(matrix));

    cout << "OK~" << endl;

    return 0;
}
