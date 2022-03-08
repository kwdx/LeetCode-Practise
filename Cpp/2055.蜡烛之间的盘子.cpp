/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = (int)s.size(), m = (int)queries.size();
        vector<int> left(n, 0), right(n, 0), sum(n + 1, 0);
        for (int i = 0, j = n - 1, p = -1, q = -1; i < n; ++i, --j) {
            if (s[i] == '|') {
                p = i;
            }
            if (s[j] == '|') {
                q = j;
            }
            left[i] = p;
            right[j] = q;
            sum[i + 1] = sum[i] + (s[i] == '*' ? 1 : 0);
        }
        vector<int> ans(m, 0);
        for (int i = 0; i < m; ++i) {
            vector<int> query = queries[i];
            int a = query[0], b = query[1];
            int c = right[a], d = left[b];
            if (c != -1 && c <= d) {
                ans[i] = sum[d + 1] - sum[c];
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    vector<vector<int>> queries;
    vector<int> res;
    
    /**
     输入：s = "**|**|***|", queries = [[2,5],[5,9]]
     输出：[2,3]
     解释：
     - queries[0] 有两个盘子在蜡烛之间。
     - queries[1] 有三个盘子在蜡烛之间。
     */
    s = "**|**|***|";
    queries = {{2,5},{5,9}};
    res = {2,3};
    assert(res == Solution().platesBetweenCandles(s, queries));
    
    /**
     输入：s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
     输出：[9,0,0,0,0]
     解释：
     - queries[0] 有 9 个盘子在蜡烛之间。
     - 另一个查询没有盘子在蜡烛之间。
     */
    s = "***|**|*****|**||**|*";
    queries = {{1,17},{4,5},{14,17},{5,11},{15,16}};
    res = {9,0,0,0,0};
    assert(res == Solution().platesBetweenCandles(s, queries));

    cout << "OK~" << endl;
    
    return 0;
}
