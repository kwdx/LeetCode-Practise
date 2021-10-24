/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        // 插入 ‘#’ 成新字符串
        string str;
        str.push_back('#');
        for(int i = 0; i < s.length(); i++) {
            str.push_back(s[i]);
            str.push_back('#');
        }
        int len = (int)str.length();
        int halfLenArr[len];
        memset(halfLenArr, 0, len * sizeof(int));

        int rightSide = 0;
        int rightSideCenter = 0;
        // 记录最长回文子串中心
        int center = 0;
        // 记录最长回文子串半径
        int longHalfLen = 0;

        for(int i = 0; i < len; i++) {
            int needExpand = true;
            if (rightSide > i) {
                halfLenArr[i] = halfLenArr[rightSideCenter * 2 - i];
                if (halfLenArr[i] + i > rightSide) {
                    halfLenArr[i] = rightSide - i;
                }
                if (halfLenArr[i] + i < rightSide) {
                    needExpand = false;
                }
            }
            if (needExpand) {
                while (i - 1 - halfLenArr[i] >= 0 && i + 1 + halfLenArr[i] < len) {
                    if (str[i - 1 - halfLenArr[i]] == str[i + 1 + halfLenArr[i]]) {
                        halfLenArr[i] += 1;
                    } else {
                        break;;
                    }
                }
                // 更新右边界
                rightSide = i + halfLenArr[i];
                rightSideCenter = i;
                if (halfLenArr[i] > longHalfLen) {
                    center = i;
                    longHalfLen = halfLenArr[i];
                }
            }
        }

        string rStr;
        for (int i = center - longHalfLen + 1; i <= center + longHalfLen; i += 2) {
            rStr.push_back(str[i]);
        }
        return rStr;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...

    string s, res;
    
    /**
     输入：s = "babad"
     输出："bab"
     解释："aba" 同样是符合题意的答案。
     */
    s = "babad";
    res = "bab";
    assert(res == Solution().longestPalindrome(s));
    
    /**
     输入：s = "cbbd"
     输出："bb"
     */
    s = "cbbd";
    res = "bb";
    assert(res == Solution().longestPalindrome(s));
    
    /**
     输入：s = "a"
     输出："a"
     */
    s = "a";
    res = "a";
    assert(res == Solution().longestPalindrome(s));
    
    /**
     输入：s = "ac"
     输出："a"
     */
    s = "ac";
    res = "a";
    assert(res == Solution().longestPalindrome(s));
    
    cout << "OK~" << endl;

    return 0;
}
