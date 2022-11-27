/*
 * @lc app=leetcode.cn id=882 lang=cpp
 *
 * [882] 细分图中的可到达结点
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        using pii = pair<int, int>;
        vector<vector<pii>> g(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], cnt = edge[2] + 1;
            g[u].emplace_back(v, cnt);
            g[v].emplace_back(u, cnt);
        }
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.emplace(0, 0);
        int dist[n];
        memset(dist, 0x3f, sizeof dist);
        dist[0] = 0;
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            for (auto& [v, cnt] : g[u]) {
                if (d + cnt < dist[v]) {
                    dist[v] = d + cnt;
                    q.emplace(dist[v], v);
                }
            }
        }
        
        int ans = 0;
        for (int& d : dist) {
            ans += d <= maxMoves;
        }
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], cnt = edge[2];
            int a = min(cnt, max(0, maxMoves - dist[u]));
            int b = min(cnt, max(0, maxMoves - dist[v]));
            ans += min(cnt, a + b);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> edges;
    int maxMoves;
    int n;
    int res;
    
    /**
     输入：edges = {{0,1,10},{0,2,1},{1,2,2}};, maxMoves = 6, n = 3
     输出：13
     解释：边的细分情况如上图所示。
     可以到达的节点已经用黄色标注出来。
     */
    edges = {{0,1,10},{0,2,1},{1,2,2}};
    maxMoves = 6;
    n = 3;
    res = 13;
    assert(res == Solution().reachableNodes(edges, maxMoves, n));
    
    /**
     输入：edges = {{0,1,4},{1,2,6},{0,2,8},{1,3,1}};, maxMoves = 10, n = 4
     输出：23
     */
    edges = {{0,1,4},{1,2,6},{0,2,8},{1,3,1}};
    maxMoves = 10;
    n = 4;
    res = 23;
    assert(res == Solution().reachableNodes(edges, maxMoves, n));
    
    /**
     输入：edges = {{1,2,4},{1,4,5},{1,3,1},{2,3,4},{3,4,5}};, maxMoves = 17, n = 5
     输出：1
     解释：节点 0 与图的其余部分没有连通，所以只有节点 0 可以到达。
     */
    edges = {{1,2,4},{1,4,5},{1,3,1},{2,3,4},{3,4,5}};
    maxMoves = 17;
    n = 5;
    res = 1;
    assert(res == Solution().reachableNodes(edges, maxMoves, n));
    
    cout << "OK~" << endl;
    
    return 0;
}
