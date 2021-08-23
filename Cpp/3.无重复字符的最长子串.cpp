/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int S[256] = {0};
        int left = 0, right = 0, len = 0;
        while (right < s.size()) {
            char c = s[right++];
            S[c]++;
            while (S[c] > 1) {
                S[s[left++]]--;
            }
            len = max(len, right - left);
        }
        return len;
    }

    int lengthOfLongestSubstring1(string s) {
        bool S[256] = {false};
        int left = 0, right = 0, len = 0;
        while (right < s.size()) {
            char c = s[right++];
            if (S[c]) {
                // 重复了
                len = max(len, right - left - 1);
                // 删除
                while (S[c]) {
                    char d = s[left++];
                    S[d] = false;
                }
            }
            S[c] = true;
        }
        return max(len, right - left);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string s;
    int res;

    /**
     输入: s = "abcabcbb"
     输出: 3
     解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
     */
    s = "abcabcbb";
    res = 3;
    assert(res == Solution().lengthOfLongestSubstring(s));

    /**
     输入: s = "bbbbb"
     输出: 1
     解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
     */
    s = "bbbbb";
    res = 1;
    assert(res == Solution().lengthOfLongestSubstring(s));

    /**
     输入: s = "pwwkew"
     输出: 3
     解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
          请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
     */
    s = "pwwkew";
    res = 3;
    assert(res == Solution().lengthOfLongestSubstring(s));

    /**
     输入: s = ""
     输出: 0
     */
    s = "";
    res = 0;
    assert(res == Solution().lengthOfLongestSubstring(s));
    
    s = " ";
    res = 1;
    assert(res == Solution().lengthOfLongestSubstring(s));

    cout << "OK~" << endl;

    return 0;
}
