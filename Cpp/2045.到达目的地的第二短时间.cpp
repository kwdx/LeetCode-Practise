/*
 * @lc app=leetcode.cn id=2045 lang=cpp
 *
 * [2045] 到达目的地的第二短时间
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // path[i][0] 表示从 1 到 i 的最短路长度，path[i][1] 表示从 1 到 i 的严格次短路长度
        vector<vector<int>> path(n + 1, vector<int>(2, INT_MAX));
        path[1][0] = 0;
        queue<pair<int, int>> q;
        q.push({1, 0});
        while (path[n][1] == INT_MAX) {
            auto [cur, len] = q.front();
            q.pop();
            for (auto next : graph[cur]) {
                if (len + 1 < path[next][0]) {
                    path[next][0] = len + 1;
                    q.push({next, len + 1});
                } else if (len + 1 > path[next][0] && len + 1 < path[next][1]) {
                    path[next][1] = len + 1;
                    q.push({next, len + 1});
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < path[n][1]; i++) {
            if (ret % (2 * change) >= change) {
                ret = ret + (2 * change - ret % (2 * change));
            }
            ret = ret + time;
        }
        return ret;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    vector<vector<int>> edges;
    int time;
    int change;
    int res;
    
    /**
     输入：n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
     输出：13
     解释：
     上面的左图展现了给出的城市交通图。
     右图中的蓝色路径是最短时间路径。
     花费的时间是：
     - 从节点 1 开始，总花费时间=0
     - 1 -> 4：3 分钟，总花费时间=3
     - 4 -> 5：3 分钟，总花费时间=6
     因此需要的最小时间是 6 分钟。

     右图中的红色路径是第二短时间路径。
     - 从节点 1 开始，总花费时间=0
     - 1 -> 3：3 分钟，总花费时间=3
     - 3 -> 4：3 分钟，总花费时间=6
     - 在节点 4 等待 4 分钟，总花费时间=10
     - 4 -> 5：3 分钟，总花费时间=13
     因此第二短时间是 13 分钟。
     */
    n = 5;
    edges = {{1,2},{1,3},{1,4},{3,4},{4,5}};
    time = 3;
    change = 5;
    res = 13;
    assert(res == Solution().secondMinimum(n, edges, time, change));
    
    /**
     输入：n = 2, edges = [[1,2]], time = 3, change = 2
     输出：11
     解释：
     最短时间路径是 1 -> 2 ，总花费时间 = 3 分钟
     最短时间路径是 1 -> 2 -> 1 -> 2 ，总花费时间 = 11 分钟
     */
    n = 2;
    edges = {{1,2}};
    time = 3;
    change = 2;
    res = 11;
    assert(res == Solution().secondMinimum(n, edges, time, change));

    cout << "OK~" << endl;

    return 0;
}
