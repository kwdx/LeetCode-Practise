/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

#include <iostream>
#include <string>

using namespace std;

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

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s, res;
    int numRows;
    
    /**
     输入：s = "PAYPALISHIRING", numRows = 3
     输出："PAHNAPLSIIGYIR"
     */
    s = "PAYPALISHIRING";
    numRows = 3;
    res = "PAHNAPLSIIGYIR";
    assert(res == Solution().convert(s, numRows));
    
    /**
     输入：s = "PAYPALISHIRING", numRows = 4
     输出："PINALSIGYAHRPI"
     解释：
     P     I    N
     A   L S  I G
     Y A   H R
     P     I
     */
    s = "PAYPALISHIRING";
    numRows = 4;
    res = "PINALSIGYAHRPI";
    assert(res == Solution().convert(s, numRows));
    
    /**
     输入：s = "A", numRows = 1
     输出："A"
     */
    s = "A";
    numRows = 1;
    res = "A";
    assert(res == Solution().convert(s, numRows));

    cout << "OK~" << endl;
    
    return 0;
}
