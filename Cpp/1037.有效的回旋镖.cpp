/*
 * @lc app=leetcode.cn id=1037 lang=cpp
 *
 * [1037] 有效的回旋镖
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int a = points[1][0] - points[0][0], b = points[1][1] - points[0][1];
        int x = points[2][0] - points[0][0], y = points[2][1] - points[0][1];
        return a * y - b * x != 0;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> points;
    bool res;
    
    /**
     输入：points = [[1,1],[2,3],[3,2]]
     输出：true
     */
    points = {{1,1},{2,3},{3,2}};
    res = true;
    assert(res == Solution().isBoomerang(points));
    
    /**
     输入：points = [[1,1],[2,2],[3,3]]
     输出：false
     */
    points = {{1,1},{2,2},{3,3}};
    res = false;
    assert(res == Solution().isBoomerang(points));

    cout << "OK~" << endl;
    
    return 0;
}
