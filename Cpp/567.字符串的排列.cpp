/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char c : s1) {
            need[c]++;
        }
        
        int left = 0, right = 0, valid = 0;
        while (right < s2.size()) {
            char c = s2[right++];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            
            while (valid == need.size()) {
                if (right - left == s1.size()) {
                    return true;
                }
                char d = s2[left++];
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string s1, s2;

    /**
     输入：s1 = "ab" s2 = "eidbaooo"
     输出：true
     解释：s2 包含 s1 的排列之一 ("ba").
     */
    s1 = "ab";
    s2 = "eidbaooo";
    assert(Solution().checkInclusion(s1, s2));

    /**
     输入：s1= "ab" s2 = "eidboaoo"
     输出：false
     */
    s1 = "ab";
    s2 = "eidboaoo";
    assert(!Solution().checkInclusion(s1, s2));

    cout << "OK~" << endl;

    return 0;
}
