/*
 * @lc app=leetcode.cn id=1620 lang=cpp
 *
 * [1620] 网络信号最好的坐标
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int xMax = 0;
        int yMax = 0;
        for (vector<int>& tower : towers) {
            xMax = max(tower[0], xMax);
            yMax = max(tower[1], yMax);
        }
        vector<int> ans = {0,0};
        int maxQuality = 0;
        for (int x = 0; x <= xMax; ++x) {
            for (int y = 0; y <= yMax; ++y) {
                int quality = 0;
                vector<int> point = {x, y};
                for (vector<int>& tower : towers) {
                    int squaredDistance = getSquaredDistance(point, tower);
                    if (squaredDistance <= radius * radius) {
                        double distance = sqrt((double)squaredDistance);
                        quality += floor((double)tower[2] / (1 + distance));
                    }
                }
                if (quality > maxQuality) {
                    ans = point;
                    maxQuality = quality;
                }
            }
        }
        return ans;
    }
    
    int getSquaredDistance(vector<int>& point, vector<int>& tower) {
        return (tower[0] - point[0]) * (tower[0] - point[0]) + (tower[1] - point[1]) * (tower[1] - point[1]);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> towers;
    int radius;
    vector<int> res;
    
    towers = {{31,13,33},{24,45,38},{28,32,23},{7,23,22},{41,50,33},{47,21,3},{3,33,39},{11,38,5},{26,20,28},{48,39,16},{34,29,25}};
    radius = 21;
    res = {24,45};
    assert(res == Solution().bestCoordinate(towers, radius));
    
    /**
     输入：towers = [[1,2,5],[2,1,7],[3,1,9]], radius = 2
     输出：[2,1]
     解释：
     坐标 (2, 1) 信号强度之和为 13
     - 塔 (2, 1) 强度参数为 7 ，在该点强度为 ⌊7 / (1 + sqrt(0)⌋ = ⌊7⌋ = 7
     - 塔 (1, 2) 强度参数为 5 ，在该点强度为 ⌊5 / (1 + sqrt(2)⌋ = ⌊2.07⌋ = 2
     - 塔 (3, 1) 强度参数为 9 ，在该点强度为 ⌊9 / (1 + sqrt(1)⌋ = ⌊4.5⌋ = 4
     没有别的坐标有更大的信号强度。
     */
    towers = {{1,2,5},{2,1,7},{3,1,9}};
    radius = 2;
    res = {2,1};
    assert(res == Solution().bestCoordinate(towers, radius));
    
    /**
     输入：towers = [[23,11,21]], radius = 9
     输出：[23,11]
     解释：由于仅存在一座信号塔，所以塔的位置信号强度最大。
     */
    towers = {{23,11,21}};
    radius = 9;
    res = {23,11};
    assert(res == Solution().bestCoordinate(towers, radius));
    
    /**
     输入：towers = [[1,2,13],[2,1,7],[0,1,9]], radius = 2
     输出：[1,2]
     解释：坐标 (1, 2) 的信号强度最大。
     */
    towers = {{1,2,13},{2,1,7},{0,1,9}};
    radius = 2;
    res = {1,2};
    assert(res == Solution().bestCoordinate(towers, radius));
    
    cout << "OK~" << endl;
    
    return 0;
}
