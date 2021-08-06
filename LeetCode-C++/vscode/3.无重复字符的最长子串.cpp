/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = (int)s.length();
        if (len == 0) return 0;
        int S[256] = {0};
        int i, j, m = 0;
        for (i = 0, j= 0; j < len; j++) {
            S[s[j]]++;
            while (S[s[j]] > 1) {
                S[s[i]]--;
                i++;
            }
            m = max(m, j - i + 1);
        }
        return m;
    }
};
// @lc code=end

