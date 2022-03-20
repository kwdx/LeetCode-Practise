/*
 * @lc app=leetcode.cn id=2039 lang=cpp
 *
 * [2039] 网络空闲的时刻
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = (int)patience.size();
        vector<vector<int>> graph(n);
        
        for (auto& e : edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        
        // 记录每个服务器到主服务器的最短距离
        vector<int> dist(n, 0);
        queue<int> q;
        q.emplace(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& v : graph[u]) {
                if (v != 0 && dist[v] == 0) {
                    // 记录新节点的最短距离
                    dist[v] = dist[u] + 1;
                    q.emplace(v);
                }
            }
        }
        
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int di = 2 * dist[i];
            int t = patience[i];

            if (di <= patience[i]) {
                // 不会重发
                ans = max(ans, di);
            } else {
                // 发生重发，该服务器从(di + 最后1次重发时间）
                ans = max(ans, di + (di - 1) / t * t);
            }
        }
        // 下一秒才会空闲
        return ans + 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> edges;
    vector<int> patience;
    int res;
    
    /**
     输入：edges = [[0,1],[1,2]], patience = [0,2,1]
     输出：8
     解释：
     0 秒最开始时，
     - 数据服务器 1 给主服务器发出信息（用 1A 表示）。
     - 数据服务器 2 给主服务器发出信息（用 2A 表示）。

     1 秒时，
     - 信息 1A 到达主服务器，主服务器立刻处理信息 1A 并发出 1A 的回复信息。
     - 数据服务器 1 还没收到任何回复。距离上次发出信息过去了 1 秒（1 < patience[1] = 2），所以不会重发信息。
     - 数据服务器 2 还没收到任何回复。距离上次发出信息过去了 1 秒（1 == patience[2] = 1），所以它重发一条信息（用 2B 表示）。

     2 秒时，
     - 回复信息 1A 到达服务器 1 ，服务器 1 不会再重发信息。
     - 信息 2A 到达主服务器，主服务器立刻处理信息 2A 并发出 2A 的回复信息。
     - 服务器 2 重发一条信息（用 2C 表示）。
     ...
     4 秒时，
     - 回复信息 2A 到达服务器 2 ，服务器 2 不会再重发信息。
     ...
     7 秒时，回复信息 2D 到达服务器 2 。

     从第 8 秒开始，不再有任何信息在服务器之间传输，也不再有信息到达服务器。
     所以第 8 秒是网络变空闲的最早时刻。
     */
    edges = {{0,1},{1,2}};
    patience = {0,2,1};
    res = 8;
    assert(res == Solution().networkBecomesIdle(edges, patience));
    
    /**
     输入：edges = [[0,1],[0,2],[1,2]], patience = [0,10,10]
     输出：3
     解释：数据服务器 1 和 2 第 2 秒初收到回复信息。
     从第 3 秒开始，网络变空闲。
     */
    edges = {{0,1},{0,2},{1,2}};
    patience = {0,10,10};
    res = 3;
    assert(res == Solution().networkBecomesIdle(edges, patience));

    cout << "OK~" << endl;
    
    return 0;
}
