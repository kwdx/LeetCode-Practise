/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int ans = 1;
        for (int i = 2; i <= num / i; ++i) {
            if (num % i == 0) {
                ans += i;
                if (i * i != num) {
                    ans += num / i;
                }
            }
        }
        return ans == num;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int num;
    bool res;
    
    /**
     输入：num = 28
     输出：true
     解释：28 = 1 + 2 + 4 + 7 + 14
     1, 2, 4, 7, 和 14 是 28 的所有正因子。
     */
    num = 28;
    res = true;
    assert(res == Solution().checkPerfectNumber(num));
    
    /**
     输入：num = 6
     输出：true
     */
    num = 6;
    res = true;
    assert(res == Solution().checkPerfectNumber(num));
    
    /**
     输入：num = 496
     输出：true
     */
    num = 496;
    res = true;
    assert(res == Solution().checkPerfectNumber(num));
    
    /**
     输入：num = 8128
     输出：true
     */
    num = 8128;
    res = true;
    assert(res == Solution().checkPerfectNumber(num));
    
    /**
     输入：num = 2
     输出：false
     */
    num = 2;
    res = false;
    assert(res == Solution().checkPerfectNumber(num));
    
    cout << "OK~" << endl;

    return 0;
}
