/*
 * @lc app=leetcode.cn id=1796 lang=cpp
 *
 * [1796] 字符串中第二大的数字
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int secondHighest(string s) {
        int mask = 0;
        for (char& c : s) {
            if (isdigit(c)) {
                mask |= 1 << (c - '0');
            }
        }
        for (int i = 9, cnt = 0; ~i; --i) {
            if (mask >> i & 1 && ++cnt == 2) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int res;
    
    /**
     输入：s = "dfa12321afd"
     输出：2
     解释：出现在 s 中的数字包括 [1, 2, 3] 。第二大的数字是 2 。
     */
    s = "dfa12321afd";
    res = 2;
    assert(res == Solution().secondHighest(s));
    
    /**
     输入：s = "abc1111"
     输出：-1
     解释：出现在 s 中的数字只包含 [1] 。没有第二大的数字。
     */
    s = "abc1111";
    res = -1;
    assert(res == Solution().secondHighest(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
