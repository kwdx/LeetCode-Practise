/*
 * @lc app=leetcode.cn id=688 lang=cpp
 *
 * [688] “马”在棋盘上的概率
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    vector<vector<int>> dirs = {{-1,-2},{-1,2},{1,-2},{1,2},{-2,1},{-2,-1},{2,1},{2,-1}};
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> f(n, vector<vector<double>>(n, vector<double>(k + 1, 0)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j][0] = 1;
            }
        }
        for (int p = 1; p <= k; p++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (vector<int>& d : dirs) {
                        int nx = i + d[0], ny = j + d[1];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        f[i][j][p] += f[nx][ny][p - 1] / 8;
                    }
                }
            }
        }
        return f[row][column][k];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, k, row, column;
    double res;
    
    /**
     输入: n = 3, k = 2, row = 0, column = 0
     输出: 0.0625
     解释: 有两步(到(1,2)，(2,1))可以让骑士留在棋盘上。
     在每一个位置上，也有两种移动可以让骑士留在棋盘上。
     骑士留在棋盘上的总概率是0.0625。
     */
//    n = 3;
//    k = 2;
//    row = 0;
//    column = 0;
//    res = 0.0625;
//    assert(res == Solution().knightProbability(n, k, row, column));
//
//    /**
//     输入: n = 1, k = 0, row = 0, column = 0
//     输出: 1.00000
//     */
//    n = 1;
//    k = 0;
//    row = 0;
//    column = 0;
//    res = 1.00000;
//    assert(res == Solution().knightProbability(n, k, row, column));
    
    n = 1;
    k = 1;
    row = 0;
    column = 0;
    res = 0.0;
    assert(res == Solution().knightProbability(n, k, row, column));
    
    cout << "OK~" << endl;
    
    return 0;
}
