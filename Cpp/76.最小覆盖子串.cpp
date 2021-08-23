/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        
        for (char c : t) {
            need[c]++;
        }
        
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        
        while (right < s.size()) {
            char c = s[right++];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            while (valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char d = s[left++];
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        
        if (len == INT_MAX) {
            return "";
        }
        string res;
        for (int i = 0; i < len; i++) {
            res.push_back(s[i + start]);
        }
        
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string s, t, res;

    /**
     输入：s = "ADOBECODEBANC", t = "ABC"
     输出："BANC"
     */
    s = "ADOBECODEBANC";
    t = "ABC";
    res = "BANC";
    assert(res == Solution().minWindow(s, t));

    /**
     输入：s = "a", t = "a"
     输出："a"
     */
    s = "a";
    t = "a";
    res = "a";
    assert(res == Solution().minWindow(s, t));

    /**
     输入: s = "a", t = "aa"
     输出: ""
     解释: t 中两个字符 'a' 均应包含在 s 的子串中，
     因此没有符合条件的子字符串，返回空字符串。
     */
    s = "a";
    t = "aa";
    res = "";
    assert(res == Solution().minWindow(s, t));

    s = "";
    t = "";
    res = "";
    assert(res == Solution().minWindow(s, t));

    cout << "OK~" << endl;

    return 0;
}
