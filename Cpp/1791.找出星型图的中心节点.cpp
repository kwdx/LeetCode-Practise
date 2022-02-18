/*
 * @lc app=leetcode.cn id=1791 lang=cpp
 *
 * [1791] 找出星型图的中心节点
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0], b = edges[0][1];
        return a == edges[1][0] || a == edges[1][1] ? a : b;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> edges;
    int res;
    
    /**
     输入：edges = [[1,2],[2,3],[4,2]]
     输出：2
     解释：如上图所示，节点 2 与其他每个节点都相连，所以节点 2 是中心节点。
     */
    edges = {{1,2},{2,3},{4,2}};
    res = 2;
    assert(res == Solution().findCenter(edges));

    /**
     输入：edges = [[1,2],[5,1],[1,3],[1,4]]
     输出：1
     */
    edges = {{1,2},{5,1},{1,3},{1,4}};
    res = 1;
    assert(res == Solution().findCenter(edges));
    
    cout << "OK~" << endl;
    
    return 0;
}
