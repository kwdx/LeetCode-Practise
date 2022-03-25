/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int res;
    
    /**
     输入：n = 3
     输出：0
     解释：3! = 6 ，不含尾随 0
     */
    n = 3;
    res = 0;
    assert(res == Solution().trailingZeroes(n));
    
    /**
     输入：n = 5
     输出：1
     解释：5! = 120 ，有一个尾随 0
     */
    n = 5;
    res = 1;
    assert(res == Solution().trailingZeroes(n));
    
    /**
     输入：n = 0
     输出：0
     */
    n = 0;
    res = 0;
    assert(res == Solution().trailingZeroes(n));

    cout << "OK~" << endl;
    
    return 0;
}
