/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        int multiWidth = min(ax2, bx2) - max(ax1, bx1);
        int multiHeight = min(ay2, by2) - max(ay1, by1);
        int multiArea = max(multiWidth, 0) * max(multiHeight, 0);
        return area1 + area2 - multiArea;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    int res;
    
    /**
     输入：ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
     输出：45
     */
    ax1 = -3; ay1 = 0; ax2 = 3; ay2 = 4; bx1 = 0; by1 = -1; bx2 = 9; by2 = 2;
    res = 45;
    assert(res == Solution().computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2));
    
    /**
     输入：ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
     输出：16
     */
    ax1 = -2; ay1 = -2; ax2 = 2; ay2 = 2; bx1 = -2; by1 = -2; bx2 = 2; by2 = 2;
    res = 16;
    assert(res == Solution().computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2));

    cout << "OK~" << endl;
    
    return 0;
}
