/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {int m = (int)img.size(), n = (int)img[0].size();
        vector<vector<int>> sum(m + 10, vector<int>(n + 10, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + img[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int a = max(0, i - 1), b = max(0, j - 1);
                int c = min(m - 1, i + 1), d = min(n - 1, j + 1);
                int cnt = (c - a + 1) * (d - b + 1);
                int total = sum[c + 1][d + 1] - sum[a][d + 1] - sum[c + 1][b] + sum[a][b];
                ans[i][j] = total / cnt;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> img;
    vector<vector<int>> res;
    
    /**
     输入:img = [[1,1,1],[1,0,1],[1,1,1]]
     输出:[[0, 0, 0],[0, 0, 0], [0, 0, 0]]
     解释:
     对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
     对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
     对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
     */
    img = {{1,1,1},{1,0,1},{1,1,1}};
    res = {{0,0,0},{0,0,0},{0,0,0}};
    assert(res == Solution().imageSmoother(img));
    
    /**
     输入: img = [[100,200,100],[200,50,200],[100,200,100]]
     输出: [[137,141,137],[141,138,141],[137,141,137]]
     解释:
     对于点 (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
     对于点 (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
     对于点 (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138
     */
    img = {{100,200,100},{200,50,200},{100,200,100}};
    res = {{137,141,137},{141,138,141},{137,141,137}};
    assert(res == Solution().imageSmoother(img));

    cout << "OK~" << endl;
    
    return 0;
}
