/*
 * @lc app=leetcode.cn id=940 lang=cpp
 *
 * [940] 不同的子序列 II
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    static constexpr int mod = 1000000007;
public:
    int distinctSubseqII(string s) {
        vector<int> g(26, 0);
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            int total = 1;
            for (int j = 0; j < 26; ++j) {
                total = (total + g[j]) % mod;
            }
            g[s[i] - 'a'] = total;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + g[i]) % mod;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int res;
    
    /**
     输入：s = "abc"
     输出：7
     解释：7 个不同的子序列分别是 "a", "b", "c", "ab", "ac", "bc", 以及 "abc"。
     */
    s = "abc";
    res = 7;
    assert(res == Solution().distinctSubseqII(s));
    
    /**
     输入：s = "aba"
     输出：6
     解释：6 个不同的子序列分别是 "a", "b", "ab", "ba", "aa" 以及 "aba"。
     */
    s = "aba";
    res = 6;
    assert(res == Solution().distinctSubseqII(s));
    
    /**
     输入：s = "aaa"
     输出：3
     解释：3 个不同的子序列分别是 "a", "aa" 以及 "aaa"。
     */
    s = "aaa";
    res = 3;
    assert(res == Solution().distinctSubseqII(s));

    cout << "OK~" << endl;
    
    return 0;
}

