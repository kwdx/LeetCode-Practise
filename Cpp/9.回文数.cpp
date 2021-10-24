/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int revertNum = 0;
        while (x > revertNum) {
            revertNum = revertNum * 10 + x % 10;
            x = x / 10;
        }
        return x == revertNum || x == revertNum / 10;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int x;
    bool res;
    
    /**
     输入：x = 121
     输出：true
     */
    x = 121;
    res = true;
    assert(res == Solution().isPalindrome(x));
    
    /**
     输入：x = -121
     输出：false
     解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
     */
    x = -121;
    res = false;
    assert(res == Solution().isPalindrome(x));
    
    /**
     输入：x = 10
     输出：false
     解释：从右向左读, 为 01 。因此它不是一个回文数。
     */
    x = 10;
    res = false;
    assert(res == Solution().isPalindrome(x));
    
    /**
     输入：x = -101
     输出：false
     */
    x = -101;
    res = false;
    assert(res == Solution().isPalindrome(x));

    cout << "OK~" << endl;
    
    return 0;
}
