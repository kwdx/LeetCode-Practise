/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x != 0) {
            if (r > INT32_MAX / 10 || r < INT32_MIN / 10) return 0;
            r = r * 10 + x % 10;
            x = x / 10;
        }
        return r;
    }
};
// @lc code=end

