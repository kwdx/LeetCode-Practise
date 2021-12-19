/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1);
        vector<int> out(n + 1);
        for (vector<int> & p : trust) {
            ++in[p[1]];
            ++out[p[0]];
        }
        for (int i = 1; i <= n; ++i) {
            if (in[i] == n - 1 && out[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    vector<vector<int>> trust;
    int res;
    
    /**
     输入：n = 2, trust = [[1,2]]
     输出：2
     */
    n = 2;
    trust = {{1,2}};
    res = 2;
    assert(res == Solution().findJudge(n, trust));
    
    /**
     输入：n = 3, trust = [[1,3],[2,3]]
     输出：3
     */
    n = 3;
    trust = {{1,3},{2,3}};
    res = 3;
    assert(res == Solution().findJudge(n, trust));
    
    /**
     输入：n = 3, trust = [[1,3],[2,3],[3,1]]
     输出：-1
     */
    n = 3;
    trust = {{1,3},{2,3},{3,1}};
    res = -1;
    assert(res == Solution().findJudge(n, trust));
    
    /**
     输入：n = 3, trust = [[1,2],[2,3]]
     输出：-1
     */
    n = 3;
    trust = {{1,2},{2,3}};
    res = -1;
    assert(res == Solution().findJudge(n, trust));
    
    /**
     输入：n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
     输出：3
     */
    n = 4;
    trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};
    res = 3;
    assert(res == Solution().findJudge(n, trust));

    cout << "OK~" << endl;

    return 0;
}
