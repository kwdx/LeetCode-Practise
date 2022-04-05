/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int x = left; x <= right; ++x) {
            if ((1 << __builtin_popcount(x)) & 665772) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int left;
    int right;
    int res;
    
    /**
     输入：left = 6, right = 10
     输出：4
     解释：
     6 -> 110 (2 个计算置位，2 是质数)
     7 -> 111 (3 个计算置位，3 是质数)
     9 -> 1001 (2 个计算置位，2 是质数)
     10-> 1010 (2 个计算置位，2 是质数)
     共计 4 个计算置位为质数的数字。
     */
    left = 6;
    right = 10;
    res = 4;
    assert(res == Solution().countPrimeSetBits(left, right));
    
    /**
     输入：left = 10, right = 15
     输出：5
     解释：
     10 -> 1010 (2 个计算置位, 2 是质数)
     11 -> 1011 (3 个计算置位, 3 是质数)
     12 -> 1100 (2 个计算置位, 2 是质数)
     13 -> 1101 (3 个计算置位, 3 是质数)
     14 -> 1110 (3 个计算置位, 3 是质数)
     15 -> 1111 (4 个计算置位, 4 不是质数)
     共计 5 个计算置位为质数的数字。
     */
    left = 10;
    right = 15;
    res = 5;
    assert(res == Solution().countPrimeSetBits(left, right));
    
    cout << "OK~" << endl;
    
    return 0;
}
