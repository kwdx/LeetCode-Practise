/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool ans = (n & 1) == 1;
        while (n >>= 1) {
            if (ans == ((n & 1) == 1)) {
                return false;
            }
            ans = !ans;
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    bool res;
    
    /**
     输入：n = 5
     输出：true
     解释：5 的二进制表示是：101
     */
    n = 5;
    res = true;
    assert(res == Solution().hasAlternatingBits(n));
    
    /**
     输入：n = 7
     输出：false
     解释：7 的二进制表示是：111.
     */
    n = 7;
    res = false;
    assert(res == Solution().hasAlternatingBits(n));
    
    /**
     输入：n = 11
     输出：false
     解释：11 的二进制表示是：1011.
     */
    n = 11;
    res = false;
    assert(res == Solution().hasAlternatingBits(n));

    cout << "OK~" << endl;
    
    return 0;
}
