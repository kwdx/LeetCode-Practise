/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

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

