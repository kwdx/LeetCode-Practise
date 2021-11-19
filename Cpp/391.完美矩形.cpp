/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> points;
        int area = 0;
        int minX = rectangles[0][0];
        int minY = rectangles[0][1];
        int maxX = rectangles[0][2];
        int maxY = rectangles[0][3];
        for (auto & rect : rectangles) {
            int x = rect[0];
            int y = rect[1];
            int a = rect[2];
            int b = rect[3];
            area += (a - x) * (b - y);
            
            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, a);
            maxY = max(maxY, b);
            
            ++points[{x, y}];
            ++points[{a, b}];
            ++points[{x, b}];
            ++points[{a, y}];
        }
        if ((maxX - minX) * (maxY - minY) != area) {
            return false;
        }
        pair<int, int> leftBottom = {minX, minY};
        pair<int, int> leftTop = {minX, maxY};
        pair<int, int> rightBottom = {maxX, minY};
        pair<int, int> rightTop = {maxX, maxY};
        if (!points.count(leftBottom) || !points.count(leftTop) || !points.count(rightBottom) || !points.count(rightTop)) {
            return false;
        }
        points.erase(leftBottom);
        points.erase(leftTop);
        points.erase(rightTop);
        points.erase(rightBottom);
        for (auto & a : points) {
            if (a.second != 2 && a.second != 4) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> rectangles;
    int res;
    
    /**
     输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
     输出：true
     解释：5 个矩形一起可以精确地覆盖一个矩形区域。
     */
    rectangles = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
    res = true;
    assert(res == Solution().isRectangleCover(rectangles));

    /**
     输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
     输出：false
     解释：两个矩形之间有间隔，无法覆盖成一个矩形。
     */
    rectangles = {{1,1,2,3},{1,3,2,4},{3,1,4,2},{3,2,4,4}};
    res = false;
    assert(res == Solution().isRectangleCover(rectangles));

    /**
     输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
     输出：false
     解释：图形顶端留有空缺，无法覆盖成一个矩形。
     */
    rectangles = {{1,1,3,3},{3,1,4,2},{1,3,2,4},{3,2,4,4}};
    res = false;
    assert(res == Solution().isRectangleCover(rectangles));

    /**
     输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
     输出：false
     解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
     */
    rectangles = {{1,1,3,3},{3,1,4,2},{1,3,2,4},{2,2,4,4}};
    res = false;
    assert(res == Solution().isRectangleCover(rectangles));

    /**
     输入：rectangles = [[1,1,2,2],[1,1,2,2],[2,1,3,2]]
     输出：false
     */
    rectangles = {{1,1,2,2},{1,1,2,2},{2,1,3,2}};
    res = false;
    assert(res == Solution().isRectangleCover(rectangles));
    
    /**
     输入：rectangles = [[0,0,1,1],[0,0,2,1],[1,0,2,1],[0,2,2,3]]
     输出：false
     */
    rectangles = {{0,0,1,1},{0,0,2,1},{1,0,2,1},{0,2,2,3}};
    res = false;
    assert(res == Solution().isRectangleCover(rectangles));

    cout << "OK~" << endl;

    return 0;
}
