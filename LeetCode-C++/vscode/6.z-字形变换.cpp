/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int step = 2 * (numRows - 1);
        string rStr;
        for (int i = 0; i < numRows; i ++) {
            for (int j = i; j < s.size(); j += step) {
                rStr.push_back(s[j]);
                if (i > 0 && i < numRows - 1 && j + step - i * 2 < s.size()) {
                    rStr.push_back(s[j + step - i * 2]);
                }
            }
        }
        return rStr;
    }
};
// @lc code=end

