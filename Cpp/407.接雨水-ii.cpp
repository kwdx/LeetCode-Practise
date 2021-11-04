/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int row = (int)heightMap.size();
        int col = (int)heightMap[0].size();
        
        if (row < 3 || col < 3) {
            return 0;
        }
        
        bool visited[row][col];
        auto cmp = [](vector<int>& a, vector<int>& b) {
            return a[2] >= b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);
        
        // 四周围墙入队
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                visited[i][j] = false;
                if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                    minHeap.push({i, j, heightMap[i][j]});
                    visited[i][j] = true;
                }
            }
        }

        int ans = 0;
        int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!minHeap.empty()) {
            vector<int> wall = minHeap.top();
            minHeap.pop();
            // 访问短板四周
            for (int i = 0; i < 4; ++i) {
                int x = wall[0] + direction[i][0];
                int y = wall[1] + direction[i][1];
                // 如果位置合法且没访问过
                if (x >= 0 && x < row && y >= 0 && y < col && !visited[x][y]) {
                    if (wall[2] > heightMap[x][y]) {
                        ans += wall[2] - heightMap[x][y];
                    }
                    minHeap.push({x, y, max(heightMap[x][y], wall[2])});
                    visited[x][y] = true;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> heightMap;
    int res;
    
    /**
     输入: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
     输出: 4
     解释: 下雨后，雨水将会被上图蓝色的方块中。总的接雨水量为1+2+1=4。
     */
    heightMap = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };
    res = 4;
    assert(res == Solution().trapRainWater(heightMap));
    
    /**
     输入: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
     输出: 10
     */
    heightMap = {
        {3,3,3,3,3},
        {3,2,2,2,3},
        {3,2,1,2,3},
        {3,2,2,2,3},
        {3,3,3,3,3}
    };
    res = 10;
    assert(res == Solution().trapRainWater(heightMap));

    cout << "OK~" << endl;

    return 0;
}
