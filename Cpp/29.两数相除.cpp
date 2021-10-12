/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend > INT_MIN) return -dividend;
            return INT_MAX;
        }
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = -1;
        }
        long res = div(abs(dividend), abs(divisor));
        if (sign > 0) {
            return res > INT_MAX ? INT_MAX : (int)res;
        }
        return -(int)res;
    }
    
    int div(long a, long b) {
        if (a < b) return 0;
        long count = 1;
        long tb = b;
        while ((tb << 1) <= a) {
            count += count;
            tb <<= 1;
        }
        return (int)count + div(a - tb, b);
    }
    
};
// @lc code=end

int main(int argc, const char * argv[]) {
    int dividend, divisor, res;
    
    /**
     输入: dividend = 10, divisor = 3
     输出: 3
     解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
     */
    dividend = 10;
    divisor = 3;
    res = 3;
    assert(res == Solution().divide(dividend, divisor));
    
    /**
     输入: dividend = 7, divisor = -3
     输出: -2
     解释: 7/-3 = truncate(-2.33333..) = -2
     */
    dividend = 7;
    divisor = -3;
    res = -2;
    assert(res == Solution().divide(dividend, divisor));
    
    cout << "OK~" << endl;
    
    return 0;
}
