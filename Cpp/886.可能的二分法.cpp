/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool dfs(int cur, int nowColor, vector<int>& color, const vector<vector<int>>& g) {
        color[cur] = nowColor;
        for (auto& nextNode : g[cur]) {
            if (color[nextNode] && color[nextNode] == color[cur]) {
                return false;
            }
            if (!color[nextNode] && !dfs(nextNode, 3 ^ nowColor, color, g)) {
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n + 1, 0);
        vector<vector<int>> g(n + 1);
        for (auto& p : dislikes) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0 && !dfs(i, 1, color, g)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    vector<vector<int>> dislikes;
    bool res;
    
    /**
     输入：n = 4, dislikes = [[1,2],[1,3],[2,4]]
     输出：true
     解释：group1 [1,4], group2 [2,3]
     */
    n = 4;
    dislikes = {{1,2},{1,3},{2,4}};
    res = true;
    assert(res == Solution().possibleBipartition(n, dislikes));
    
    /**
     输入：n = 3, dislikes = [[1,2],[1,3],[2,3]]
     输出：false
     */
    n = 3;
    dislikes = {{1,2},{1,3},{2,3}};
    res = false;
    assert(res == Solution().possibleBipartition(n, dislikes));
    
    /**
     输入：n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
     输出：false
     */
    n = 5;
    dislikes = {{1,2},{2,3},{3,4},{4,5},{1,5}};
    res = false;
    assert(res == Solution().possibleBipartition(n, dislikes));

    cout << "OK~" << endl;
    
    return 0;
}

