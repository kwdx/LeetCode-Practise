/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> next(2, vector<vector<int>>(n));
        for (auto &e : redEdges) {
            next[0][e[0]].push_back(e[1]);
        }
        for (auto &e : blueEdges) {
            next[1][e[0]].push_back(e[1]);
        }
        
        // 两种类型的颜色最短路径的长度
        vector<vector<int>> dist(2, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        dist[0][0] = 0;
        dist[1][0] = 0;
        q.push({0, 0});
        q.push({0, 1});
        while (!q.empty()) {
            auto [x, t] = q.front();
            q.pop();
            for (auto y : next[1 - t][x]) {
                if (dist[1 - t][y] != INT_MAX) {
                    continue;
                }
                dist[1 - t][y] = dist[t][x] + 1;
                q.push({y, 1 - t});
            }
        }
        
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = min(dist[0][i], dist[1][i]);
            if (ans[i] == INT_MAX) {
                ans[i] = -1;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    vector<vector<int>> redEdges;
    vector<vector<int>> blueEdges;
    vector<int> res;
    
    /**
     输入：n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
     输出：[0,1,-1]
     */
    n = 3;
    redEdges = {{0,1},{1,2}};
    blueEdges = {};
    res = {0,1,-1};
    assert(res == Solution().shortestAlternatingPaths(n, redEdges, blueEdges));
    
    /**
     输入：n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
     输出：[0,1,-1]
     */
    n = 3;
    redEdges = {{0,1}};
    blueEdges = {{2,1}};
    res = {0,1,-1};
    assert(res == Solution().shortestAlternatingPaths(n, redEdges, blueEdges));
    
    /**
     输入：n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
     输出：[0,-1,-1]
     */
    n = 3;
    redEdges = {{1,0}};
    blueEdges = {{2,1}};
    res = {0,-1,-1};
    assert(res == Solution().shortestAlternatingPaths(n, redEdges, blueEdges));
    
    /**
     输入：n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
     输出：[0,1,2]
     */
    n = 3;
    redEdges = {{0,1}};
    blueEdges = {{1,2}};
    res = {0,1,2};
    assert(res == Solution().shortestAlternatingPaths(n, redEdges, blueEdges));
    
    /**
     输入：n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
     输出：[0,1,1]
     */
    n = 3;
    redEdges = {{0,1},{0,2}};
    blueEdges = {{1,0}};
    res = {0,1,1};
    assert(res == Solution().shortestAlternatingPaths(n, redEdges, blueEdges));

    cout << "OK~" << endl;
    
    return 0;
}
