/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int needL = 0;
        int needR = 0;
        for (char c : s) {
            if (c == 'L') {
                ++needR;
            } else if (c == 'R') {
                ++needL;
            }
            if (needR == needL) {
                ++res;
                needR = 0;
                needL = 0;
            }
        }

        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string s;
    int res;
    
    /**
     输入：s = "RLRRLLRLRL"
     输出：4
     解释：s 可以分割为 "RL"、"RRLL"、"RL"、"RL" ，每个子字符串中都包含相同数量的 'L' 和 'R' 。
     */
    s = "RLRRLLRLRL";
    res = 4;
    assert(res == Solution().balancedStringSplit(s));
    
    /**
     输入：s = "RLLLLRRRLR"
     输出：3
     解释：s 可以分割为 "RL"、"LLLRRR"、"LR" ，每个子字符串中都包含相同数量的 'L' 和 'R' 。
     */
    s = "RLLLLRRRLR";
    res = 3;
    assert(res == Solution().balancedStringSplit(s));
    
    /**
     输入：s = "LLLLRRRR"
     输出：1
     解释：s 只能保持原样 "LLLLRRRR".
     */
    s = "LLLLRRRR";
    res = 1;
    assert(res == Solution().balancedStringSplit(s));
    
    /**
     输入：s = "RLRRRLLRLL"
     输出：2
     解释：s 可以分割为 "RL"、"RRRLLRLL" ，每个子字符串中都包含相同数量的 'L' 和 'R' 。
     */
    s = "RLRRRLLRLL";
    res = 2;
    assert(res == Solution().balancedStringSplit(s));

    cout << "OK~" << endl;
    
    return 0;
}
