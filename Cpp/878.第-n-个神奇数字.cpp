/*
 * @lc app=leetcode.cn id=878 lang=cpp
 *
 * [878] 第 N 个神奇数字
 */

#include <iostream>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    const int MOD = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        long long l = min(a, b);
        long long r = n * l;
        int c = lcm(a, b);
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long cnt = mid / a + mid / b - mid / c;
            if (cnt >= n) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return (r + 1) % MOD;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int a;
    int b;
    int res;
    
    /**
     输入：n = 1, a = 2, b = 3
     输出：2
     */
    n = 1;
    a = 2;
    b = 3;
    res = 2;
    assert(res == Solution().nthMagicalNumber(n, a, b));
    
    /**
     输入：n = 4, a = 2, b = 3
     输出：6
     */
    n = 4;
    a = 2;
    b = 3;
    res = 6;
    assert(res == Solution().nthMagicalNumber(n, a, b));

    cout << "OK~" << endl;
    
    return 0;
}
