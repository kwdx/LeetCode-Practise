/*
 * @lc app=leetcode.cn id=1725 lang=cpp
 *
 * [1725] 可以形成最大正方形的矩形数目
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int, int> sides;
        int maxSide = 0;
        for (vector<int> & rect : rectangles) {
            int side = min(rect[0], rect[1]);
            sides[side] += 1;
            maxSide = max(side, maxSide);
        }
        return sides[maxSide];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> rectangles;
    int res;
    
    /**
     输入：rectangles = [[5,8],[3,9],[5,12],[16,5]]
     输出：3
     解释：能从每个矩形中切出的最大正方形边长分别是 [5,3,5,5] 。
     最大正方形的边长为 5 ，可以由 3 个矩形切分得到。
     */
    rectangles = {{5,8},{3,9},{5,12},{16,5}};
    res = 3;
    assert(res == Solution().countGoodRectangles(rectangles));
    
    /**
     输入：rectangles = [[2,3],[3,7],[4,3],[3,7]]
     输出：3
     */
    rectangles = {{2,3},{3,7},{4,3},{3,7}};
    res = 3;
    assert(res == Solution().countGoodRectangles(rectangles));

    cout << "OK~" << endl;

    return 0;
}
