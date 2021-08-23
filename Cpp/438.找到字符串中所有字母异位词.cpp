/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        
        unordered_map<char, int> need, window;
        
        for (char c : p) {
            need[c]++;
        }
        
        int left = 0, right = 0, valid = 0;
        
        while (right < s.size()) {
            char c = s[right++];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            while (valid == need.size()) {
                if (right - left == p.size()) {
                    res.push_back(left);
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
        
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string s, p;
    vector<int> res;

    /**
     输入: s = "cbaebabacd", p = "abc"
     输出: [0,6]
     解释:
     起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
     起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
     */
    s = "cbaebabacd";
    p = "abc";
    res = {0,6};
    assert(res == Solution().findAnagrams(s, p));

    /**
     输入: s = "abab", p = "ab"
     输出: [0,1,2]
     解释:
     起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
     起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
     起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
     */
    s = "abab";
    p = "ab";
    res = {0,1,2};
    assert(res == Solution().findAnagrams(s, p));

    cout << "OK~" << endl;

    return 0;
}
