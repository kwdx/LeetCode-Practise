/*
 * @lc app=leetcode.cn id=1405 lang=cpp
 *
 * [1405] 最长快乐字符串
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        auto my_cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return b.second > a.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(my_cmp)> q(my_cmp);
        if (a > 0) q.push({0, a});
        if (b > 0) q.push({1, b});
        if (c > 0) q.push({2, c});
        while (!q.empty()) {
            pair<int, int> cur = q.top();
            q.pop();
            int n = (int)ans.length();
            if (n >= 2 && ans[n - 1] - 'a' == cur.first && ans[n - 2] - 'a' == cur.first) {
                if (q.empty()) break;
                pair<int, int> next = q.top();
                q.pop();
                ans.push_back(next.first + 'a');
                next.second--;
                if (next.second != 0) q.push(next);
                q.push(cur);
            } else {
                ans.push_back(cur.first + 'a');
                cur.second--;
                if (cur.second != 0) q.push(cur);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a, b, c;
    string res;
    
    /**
     输入：a = 1, b = 1, c = 7
     输出："ccaccbcc"
     解释："ccbccacc" 也是一种正确答案。
     */
    a = 1;
    b = 1;
    c = 7;
    res = "ccbccacc";
    assert(res == Solution().longestDiverseString(a, b, c));
    
    /**
     输入：a = 2, b = 2, c = 1
     输出："aabbc"
     */
    a = 2;
    b = 2;
    c = 1;
    res = "abcab";// "aabbc";
    assert(res == Solution().longestDiverseString(a, b, c));
    
    /**
     输入：a = 7, b = 1, c = 0
     输出："aabaa"
     解释：这是该测试用例的唯一正确答案。
     */
    a = 7;
    b = 1;
    c = 0;
    res = "aabaa";
    assert(res == Solution().longestDiverseString(a, b, c));

    cout << "OK~" << endl;

    return 0;
}
