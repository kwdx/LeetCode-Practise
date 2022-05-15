/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        int n = (int)points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int cur = cross(points[j][0] - points[i][0],
                                    points[j][1] - points[i][1],
                                    points[k][0] - points[i][0],
                                    points[k][1] - points[i][1]);
                    ans = max(ans, abs(cur / 2.0));

                }
            }
        }
        return ans;
    }
    
    int cross(int a, int b, int c, int d) {
        return a * d - b * c;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> points;
    double res;
    
    /**
     示例:
     输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
     输出: 2
     解释:
     这五个点如下图所示。组成的橙色三角形是最大的，面积为2。
     */
    points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    res = 2;
    assert(res == Solution().largestTriangleArea(points));

    cout << "OK~" << endl;
    
    return 0;
}
