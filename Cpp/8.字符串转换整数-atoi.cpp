/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int num = 0;

        bool isPositiveFlag = true;
        bool parseNum = false;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == ' ') {
                if (!parseNum) {
                    continue;
                } else {
                    break;
                }
            } else if (ch == '-') {
                if (parseNum) break;;
                isPositiveFlag = false;
                parseNum = true;
            } else if (ch == '+') {
                if (parseNum) break;
                parseNum = true;
            } else if (ch >= '0' && ch <= '9') {
                int addNum = ch - '0';

                if (num > (INT32_MAX - addNum) / 10) {
                    return isPositiveFlag ? INT32_MAX : INT32_MIN;
                }
                num = num * 10 + addNum;
                parseNum = true;
            } else {
                break;
            }
        }
        return isPositiveFlag ? num : -num;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int res;
    
    /**
     输入：s = "42"
     输出：42
     解释：加粗的字符串为已经读入的字符，插入符号是当前读取的字符。
     第 1 步："42"（当前没有读入字符，因为没有前导空格）
              ^
     第 2 步："42"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
              ^
     第 3 步："42"（读入 "42"）
                ^
     解析得到整数 42 。
     由于 "42" 在范围 [-231, 231 - 1] 内，最终结果为 42 。
     */
    s = "42";
    res = 42;
    assert(res == Solution().myAtoi(s));
    
    /**
     输入：s = "   -42"
     输出：-42
     解释：
     第 1 步："   -42"（读入前导空格，但忽视掉）
                 ^
     第 2 步："   -42"（读入 '-' 字符，所以结果应该是负数）
                  ^
     第 3 步："   -42"（读入 "42"）
                    ^
     解析得到整数 -42 。
     由于 "-42" 在范围 [-231, 231 - 1] 内，最终结果为 -42 。
     */
    s = "   -42";
    res = -42;
    assert(res == Solution().myAtoi(s));
    
    /**
     输入：s = "4193 with words"
     输出：4193
     解释：
     第 1 步："4193 with words"（当前没有读入字符，因为没有前导空格）
              ^
     第 2 步："4193 with words"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
              ^
     第 3 步："4193 with words"（读入 "4193"；由于下一个字符不是一个数字，所以读入停止）
                  ^
     解析得到整数 4193 。
     由于 "4193" 在范围 [-231, 231 - 1] 内，最终结果为 4193 。
     */
    s = "4193 with words";
    res = 4193;
    assert(res == Solution().myAtoi(s));
    
    /**
     输入：s = "words and 987"
     输出：0
     解释：
     第 1 步："words and 987"（当前没有读入字符，因为没有前导空格）
              ^
     第 2 步："words and 987"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
              ^
     第 3 步："words and 987"（由于当前字符 'w' 不是一个数字，所以读入停止）
              ^
     解析得到整数 0 ，因为没有读入任何数字。
     由于 0 在范围 [-231, 231 - 1] 内，最终结果为 0 。
     */
    s = "words and 987";
    res = 0;
    assert(res == Solution().myAtoi(s));
    
    /**
     输入：s = "-91283472332"
     输出：-2147483648
     解释：
     第 1 步："-91283472332"（当前没有读入字符，因为没有前导空格）
              ^
     第 2 步："-91283472332"（读入 '-' 字符，所以结果应该是负数）
               ^
     第 3 步："-91283472332"（读入 "91283472332"）
                          ^
     解析得到整数 -91283472332 。
     由于 -91283472332 小于范围 [-231, 231 - 1] 的下界，最终结果被截断为 -231 = -2147483648 。
     */
    s = "-91283472332";
    res = -2147483648;
    assert(res == Solution().myAtoi(s));

    cout << "OK~" << endl;
    
    return 0;
}
