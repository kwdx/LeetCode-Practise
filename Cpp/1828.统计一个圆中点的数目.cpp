/*
 * @lc app=leetcode.cn id=1828 lang=cpp
 *
 * [1828] 统计一个圆中点的数目
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int m = (int)points.size();
        int n = (int)queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int cx = queries[i][0], cy = queries[i][1], cr = queries[i][2];
            for (int j = 0; j < m; ++j) {
                int px = points[j][0], py = points[j][1];
                if ((cx - px) * (cx - px) + (cy - py) * (cy - py) <= cr * cr) {
                    ++ans[i];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> points;
    vector<vector<int>> queries;
    vector<int> res;

    /**
     输入：points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
     输出：[3,2,2]
     解释：所有的点和圆如上图所示。
     queries[0] 是绿色的圆，queries[1] 是红色的圆，queries[2] 是蓝色的圆。
     */
    points = {{1,3},{3,3},{5,3},{2,2}};
    queries = {{2,3,1},{4,3,1},{1,1,2}};
    res = {3,2,2};
    
    /**
     输入：points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
     输出：[2,3,2,4]
     解释：所有的点和圆如上图所示。
     queries[0] 是绿色的圆，queries[1] 是红色的圆，queries[2] 是蓝色的圆，queries[3] 是紫色的圆。
     */
    points = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    queries = {{1,2,2},{2,2,2},{4,3,2},{4,3,3}};
    res = {2,3,2,4};
    assert(res == Solution().countPoints(points, queries));
    
    cout << "OK~" << endl;
    
    return 0;
}
