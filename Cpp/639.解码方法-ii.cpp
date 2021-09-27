/*
 * @lc app=leetcode.cn id=639 lang=cpp
 *
 * [639] 解码方法 II
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        static constexpr int mod = 1000000007;
        
        auto checkDigit = [](char ch) -> int {
            if (ch == '0') {
                return 0;
            }
            return ch == '*' ? 9 : 1;
        };
        auto checkDigits = [](char c0, char c1) -> int {
            if (c0 == '*' && c1 == '*') {
                return 15;
            }
            if (c0 == '*') {
                return c1 <= '6' ? 2 : 1;
            }
            if (c1 == '*') {
                if (c0 == '1') {
                    return 9;
                }
                if (c0 == '2') {
                    return 6;
                }
                return 0;
            }
            return c0 != '0' && (c0 - '0') * 10 + (c1 - '0') <= 26;
        };
        
        int n = (int)s.size();
        int a = 0, b = 1, c = 0;
        for (int i = 1; i <= n; ++i) {
            c = (long long)b * checkDigit(s[i - 1]) % mod;
            if (i > 1) {
                c = (c + (long long)a * checkDigits(s[i - 2], s[i - 1])) % mod;
            }
            a = b;
            b = c;
        }
        
        return c;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string s;
    int res;
    
    /**
     输入：s = "*"
     输出：9
     解释：这一条编码消息可以表示 "1"、"2"、"3"、"4"、"5"、"6"、"7"、"8" 或 "9" 中的任意一条。
     可以分别解码成字符串 "A"、"B"、"C"、"D"、"E"、"F"、"G"、"H" 和 "I" 。
     因此，"*" 总共有 9 种解码方法。
     */
    s = "*";
    res = 9;
    assert(res == Solution().numDecodings(s));
    
    /**
     输入：s = "1*"
     输出：18
     解释：这一条编码消息可以表示 "11"、"12"、"13"、"14"、"15"、"16"、"17"、"18" 或 "19" 中的任意一条。
     每种消息都可以由 2 种方法解码（例如，"11" 可以解码成 "AA" 或 "K"）。
     因此，"1*" 共有 9 * 2 = 18 种解码方法。
     */
    s = "1*";
    res = 18;
    assert(res == Solution().numDecodings(s));
    
    /**
     输入：s = "2*"
     输出：15
     解释：这一条编码消息可以表示 "21"、"22"、"23"、"24"、"25"、"26"、"27"、"28" 或 "29" 中的任意一条。
     "21"、"22"、"23"、"24"、"25" 和 "26" 由 2 种解码方法，但 "27"、"28" 和 "29" 仅有 1 种解码方法。
     因此，"2*" 共有 (6 * 2) + (3 * 1) = 12 + 3 = 15 种解码方法。
     */
    s = "2*";
    res = 15;
    assert(res == Solution().numDecodings(s));
    
    cout << "OK~" << endl;
    
    return 0;
}

