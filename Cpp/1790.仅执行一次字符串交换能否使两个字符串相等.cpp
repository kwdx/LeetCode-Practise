/*
 * @lc app=leetcode.cn id=1790 lang=cpp
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int a = -1, b = -1;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (a == -1) {
                    a = i;
                } else if (b == -1) {
                    b = i;
                } else {
                    return false;
                }
            }
        }
        if (a == -1) {
            return true;
        } else if (b == -1) {
            return false;
        }
        return s1[a] == s2[b] && s1[b] == s2[a];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s1;
    string s2;
    bool res;
    
    /**
     输入：s1 = "bank", s2 = "kanb"
     输出：true
     解释：例如，交换 s2 中的第一个和最后一个字符可以得到 "bank"
     */
    s1 = "bank";
    s2 = "kanb";
    res = true;
    assert(res == Solution().areAlmostEqual(s1, s2));
    
    /**
     输入：s1 = "attack", s2 = "defend"
     输出：false
     解释：一次字符串交换无法使两个字符串相等
     */
    s1 = "attack";
    s2 = "defend";
    res = false;
    assert(res == Solution().areAlmostEqual(s1, s2));
    
    /**
     输入：s1 = "kelb", s2 = "kelb"
     输出：true
     解释：两个字符串已经相等，所以不需要进行字符串交换
     */
    s1 = "kelb";
    s2 = "kelb";
    res = true;
    assert(res == Solution().areAlmostEqual(s1, s2));
    
    /**
     输入：s1 = "abcd", s2 = "dcba"
     输出：false
     */
    s1 = "abcd";
    s2 = "dcba";
    res = false;
    assert(res == Solution().areAlmostEqual(s1, s2));

    cout << "OK~" << endl;
    
    return 0;
}

