/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
//        int ans = 0;
//        while (n > 0) {
//            n &= n - 1;
//            ++ans;
//        }
//        return ans;
        return __builtin_popcount(n);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    uint32_t n;
    int res;
    
    /**
     输入：00000000000000000000000000001011
     输出：3
     解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
     */
    n = 0b00000000000000000000000000001011;
    res = 3;
    assert(res == Solution().hammingWeight(n));
    
    /**
     输入：00000000000000000000000010000000
     输出：1
     解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
     */
    n = 0b00000000000000000000000010000000;
    res = 1;
    assert(res == Solution().hammingWeight(n));
    
    /**
     输入：11111111111111111111111111111101
     输出：31
     解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
     */
    n = 0b11111111111111111111111111111101;
    res = 31;
    assert(res == Solution().hammingWeight(n));
    
    cout << "OK~" << endl;
    
    return 0;
}
