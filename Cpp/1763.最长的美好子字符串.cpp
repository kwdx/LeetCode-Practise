/*
 * @lc app=leetcode.cn id=1763 lang=cpp
 *
 * [1763] 最长的美好子字符串
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = (int)s.length();
        int idx = -1, len = 0;
        for (int i = 0; i < n; ++i) {
            int a = 0, A = 0;
            for (int j = i; j < n; ++j) {
                char c = s[j];
                if (c >= 'a' && c <= 'z') {
                    a |= (1 << (c - 'a'));
                } else {
                    A |= (1 << (c - 'A'));
                }
                if (a == A && j - i + 1 > len) {
                    idx = i; len = j - i + 1;
                }
            }
        }
        return idx == -1 ? "" : s.substr(idx, len);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    string res;
    
    /**
     输入：s = "YazaAay"
     输出："aAa"
     解释："aAa" 是一个美好字符串，因为这个子串中仅含一种字母，其小写形式 'a' 和大写形式 'A' 也同时出现了。
     "aAa" 是最长的美好子字符串。
     */
    s = "YazaAay";
    res = "aAa";
    assert(res == Solution().longestNiceSubstring(s));
    
    /**
     输入：s = "Bb"
     输出："Bb"
     解释："Bb" 是美好字符串，因为 'B' 和 'b' 都出现了。整个字符串也是原字符串的子字符串。
     */
    s = "Bb";
    res = "Bb";
    assert(res == Solution().longestNiceSubstring(s));
    
    /**
     输入：s = "c"
     输出：""
     解释：没有美好子字符串。
     */
    s = "c";
    res = "";
    assert(res == Solution().longestNiceSubstring(s));
    
    /**
     输入：s = "dDzeE"
     输出："dD"
     解释："dD" 和 "eE" 都是最长美好子字符串。
     由于有多个美好子字符串，返回 "dD" ，因为它出现得最早。
     */
    s = "dDzeE";
    res = "dD";
    assert(res == Solution().longestNiceSubstring(s));

    cout << "OK~" << endl;

    return 0;
}
