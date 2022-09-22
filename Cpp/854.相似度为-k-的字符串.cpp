/*
 * @lc app=leetcode.cn id=854 lang=cpp
 *
 * [854] 相似度为 K 的字符串
 */

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = (int)s1.size();
        queue<pair<string, int>> q;
        unordered_set<string> visit;
        q.emplace(s1, 0);
        for (int step = 0; ; ++step) {
            int sz = (int)q.size();
            for (int i = 0; i < sz; ++i) {
                auto [cur, pos] = q.front();
                q.pop();
                if (cur == s2) {
                    return step;
                }
                while (pos < n && cur[pos] == s2[pos]) {
                    ++pos;
                }
                for (int j = pos + 1; j < n; ++j) {
                    if (cur[j] != s2[j] && cur[j] == s2[pos]) {
                        swap(cur[pos], cur[j]);
                        if (!visit.count(cur)) {
                            visit.emplace(cur);
                            q.emplace(cur, pos + 1);
                        }
                        swap(cur[pos], cur[j]);
                    }
                }
            }
        }
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s1;
    string s2;
    int res;
    
    /**
     输入：s1 = "ab", s2 = "ba"
     输出：1
     */
    s1 = "ab";
    s2 = "ba";
    res = 1;
    assert(res == Solution().kSimilarity(s1, s2));
    
    /**
     输入：s1 = "abc", s2 = "bca"
     输出：2
     */
    s1 = "abc";
    s2 = "bca";
    res = 2;
    assert(res == Solution().kSimilarity(s1, s2));

    cout << "OK~" << endl;
    
    return 0;
}
