/*
 * @lc app=leetcode.cn id=1719 lang=cpp
 *
 * [1719] 重构一棵树的方案数
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto &p : pairs) {
            adj[p[0]].emplace(p[1]);
            adj[p[1]].emplace(p[0]);
        }
        /* 检测是否存在根节点*/
        int root = -1;
        for (auto &[node, neighbours] : adj) {
            if (neighbours.size() == adj.size() - 1) {
                root = node;
                break;
            }
        }
        if (root == -1) {
            return 0;
        }

        int res = 1;
        for (auto &[node, neighbours] : adj) {
            if (node == root) {
                continue;
            }
            int currDegree = (int)neighbours.size();
            int parent = -1;
            int parentDegree = INT_MAX;

            /* 根据 degree 的大小找到 node 的父节点 parent */
            for (auto &neighbour : neighbours) {
                if (adj[neighbour].size() < parentDegree && adj[neighbour].size() >= currDegree) {
                    parent = neighbour;
                    parentDegree = (int)adj[neighbour].size();
                }
            }
            if (parent == -1) {
                return 0;
            }

            /* 检测 neighbours 是否是 adj[parent] 的子集 */
            for (auto &neighbour : neighbours) {
                if (neighbour == parent) {
                    continue;
                }
                if (!adj[parent].count(neighbour)) {
                    return 0;
                }
            }
            if (parentDegree == currDegree) {
                res = 2;
            }
        }
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> pairs;
    int res;
    
    /**
     输入：pairs = [[1,2],[2,3]]
     输出：1
     解释：如上图所示，有且只有一个符合规定的有根树。
     */
    pairs = {{1,2},{2,3}};
    res = 1;
    assert(res == Solution().checkWays(pairs));
    
    /**
     输入：pairs = [[1,2],[2,3],[1,3]]
     输出：2
     解释：有多个符合规定的有根树，其中三个如上图所示。
     */
    pairs = {{1,2},{2,3},{1,3}};
    res = 2;
    assert(res == Solution().checkWays(pairs));
    
    /**
     输入：pairs = [[1,2],[2,3],[2,4],[1,5]]
     输出：0
     解释：没有符合规定的有根树。
     */
    pairs = {{1,2},{2,3},{2,4},{1,5}};
    res = 0;
    assert(res == Solution().checkWays(pairs));

    cout << "OK~" << endl;

    return 0;
}
