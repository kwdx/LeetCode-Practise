/*
 * @lc app=leetcode.cn id=1779 lang=cpp
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        int minDis = -1;
        for (int i = 0; i < points.size(); ++i) {
            if (x == points[i][0] || y == points[i][1]) {
                int dis = (points[i][0] - x) * (points[i][0] - x) + (points[i][1] - y) * (points[i][1] - y);
                if (ans == -1 || dis < minDis) {
                    ans = i;
                    minDis = dis;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int x;
    int y;
    vector<vector<int>> points;
    int res;
    
    /**
     输入：x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
     输出：2
     解释：所有点中，[3,1]，[2,4] 和 [4,4] 是有效点。有效点中，[2,4] 和 [4,4] 距离你当前位置的曼哈顿距离最小，都为 1 。[2,4] 的下标最小，所以返回 2 。
     */
    x = 3;
    y = 4;
    points = {{1,2},{3,1},{2,4},{2,3},{4,4}};
    res = 2;
    assert(res == Solution().nearestValidPoint(x, y, points));
    
    /**
     输入：x = 3, y = 4, points = [[3,4]]
     输出：0
     提示：答案可以与你当前所在位置坐标相同。
     */
    x = 3;
    y = 4;
    points = {{1,2},{3,1},{2,4},{2,3},{4,4}};
    res = 2;
    assert(res == Solution().nearestValidPoint(x, y, points));
    
    /**
     输入：x = 3, y = 4, points = [[2,3]]
     输出：-1
     解释：没有 有效点。
     */
    x = 3;
    y = 4;
    points = {{1,2},{3,1},{2,4},{2,3},{4,4}};
    res = 2;
    assert(res == Solution().nearestValidPoint(x, y, points));
    
    cout << "OK~" << endl;
    
    return 0;
}
