/*
 * @lc app=leetcode.cn id=1610 lang=cpp
 *
 * [1610] 可见点的最大数目
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int x = location[0], y = location[1];
        
        int samePoints = 0;
        vector<double> polarDegrees;
        for (vector<int>& point : points) {
            if (point[0] == x && point[1] == y) {
                ++samePoints;
            } else {
                double degree = atan2(point[1] - y, point[0] - x);
                polarDegrees.emplace_back(degree);
            }
        }
        sort(polarDegrees.begin(), polarDegrees.end());
        
        int m = (int)polarDegrees.size();
        for (int i = 0; i < m; ++i) {
            polarDegrees.emplace_back(polarDegrees[i] + 2 * M_PI);
        }
        
        int maxPoints = 0;
        int right = 0;
        double degree = angle * M_PI / 180;
        for (int i = 0; i < m; ++i) {
            while (right < polarDegrees.size() && polarDegrees[right] <= polarDegrees[i] + degree) {
                ++right;
            }
            maxPoints = max(maxPoints, right - i);
        }
        return maxPoints + samePoints;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> points;
    int angle;
    vector<int> location;
    int res;
    
    /**
     输入：points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
     输出：3
     解释：阴影区域代表你的视野。在你的视野中，所有的点都清晰可见，尽管 [2,2] 和 [3,3]在同一条直线上，你仍然可以看到 [3,3] 。
     */
    points = {{2,1},{2,2},{3,3}};
    angle = 90;
    location = {1,1};
    res = 3;
    assert(res == Solution().visiblePoints(points, angle, location));
    
    /**
     输入：points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
     输出：4
     解释：在你的视野中，所有的点都清晰可见，包括你所在位置的那个点。
     */
    points = {{2,1},{2,2},{3,4},{1,1}};
    angle = 90;
    location = {1,1};
    res = 4;
    assert(res == Solution().visiblePoints(points, angle, location));
    
    /**
     输入：points = [[1,0],[2,1]], angle = 13, location = [1,1]
     输出：1
     解释：如图所示，你只能看到两点之一。
     */
    points = {{1,0},{2,1}};
    angle = 13;
    location = {1,1};
    res = 1;
    assert(res == Solution().visiblePoints(points, angle, location));

    cout << "OK~" << endl;

    return 0;
}
