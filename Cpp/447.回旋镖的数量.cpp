/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for (vector<int>& point : points) {
            unordered_map<int, int> distances;
            for (vector<int>& p : points) {
                int dis = (point[0] - p[0]) * (point[0] - p[0]) + (point[1] - p[1]) * (point[1] - p[1]);
                ++distances[dis];
            }
            for (auto &[key, val] : distances) {
                res += val * (val - 1);
            }
        }
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<vector<int>> points;
    int res;
    
    /**
     输入：points = [[0,0],[1,0],[2,0]]
     输出：2
     解释：两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
     */
    points = {
        {0,0},
        {1,0},
        {2,0}
    };
    res = 2;
    assert(res == Solution().numberOfBoomerangs(points));

    /**
     输入：points = [[1,1],[2,2],[3,3]]
     输出：2
     */
    points = {
        {1,1},
        {2,2},
        {3,3}
    };
    res = 2;
    assert(res == Solution().numberOfBoomerangs(points));

    /**
     输入：points = [[1,1]]
     输出：0
     */
    points = {
        {1,1}
    };
    res = 0;
    assert(res == Solution().numberOfBoomerangs(points));
    
    /**
     输入：points = [[0,0],[1,0],[-1,0],[0,1],[0,-1]]
     输出：20
     */
    points = {
        {0,0},
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    res = 20;
    assert(res == Solution().numberOfBoomerangs(points));
    
    cout << "OK~" << endl;
    
    return 0;
}
