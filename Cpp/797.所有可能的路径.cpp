/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        res.clear();
        travel(graph, 0, vector<int>());
        return res;
    }

private:
    vector<vector<int>> res;
    void travel(vector<vector<int>>& graph, int node, vector<int> path) {
        path.push_back(node);

        if (node == graph.size() - 1) {
            // 走到终点了
            res.push_back(vector<int>(path));
            path.pop_back();
            return;
        }

        for (int next : graph[node]) {
            travel(graph, next, path);
        }
        path.pop_back();
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    vector<vector<int>> graph;
    vector<vector<int>> res;

    /**
     输入：graph = [[1,2],[3],[3],[]]
     输出：[[0,1,3],[0,2,3]]
     解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3
     */
    graph = {
        {1, 2},
        {3},
        {3},
        {}
    };
    res = Solution().allPathsSourceTarget(graph);
    for (vector<int> path : res) {
        for (int node : path)
            cout << node << " ";
        cout << endl;
    }

    /**
     输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
     输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
     */
    graph = {
        {4,3,1},
        {3,2,4},
        {3},
        {4},
        {}
    };
    res = Solution().allPathsSourceTarget(graph);
    for (vector<int> path : res) {
        for (int node : path)
            cout << node << " ";
        cout << endl;
    }

    /**
     输入：graph = [[1],[]]
     输出：[[0,1]]
     */
    graph = {
        {1},
        {}
    };
    res = Solution().allPathsSourceTarget(graph);
    for (vector<int> path : res) {
        for (int node : path)
            cout << node << " ";
        cout << endl;
    }

    /**
     输入：graph = [[1,2,3],[2],[3],[]]
     输出：[[0,1,2,3],[0,2,3],[0,3]]
     */
    graph = {
        {1,2,3},
        {2},
        {3},
        {}
    };
    res = Solution().allPathsSourceTarget(graph);
    for (vector<int> path : res) {
        for (int node : path)
            cout << node << " ";
        cout << endl;
    }

    /**
     输入：graph = [[1,3],[2],[3],[]]
     输出：[[0,1,2,3],[0,3]]
     */
    graph = {
        {1,3},
        {2},
        {3},
        {}
    };
    res = Solution().allPathsSourceTarget(graph);
    for (vector<int> path : res) {
        for (int node : path)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}
