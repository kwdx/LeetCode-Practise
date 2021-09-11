/*
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] 不含连续1的非负整数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int findIntegers(int n) {
        int res = 0;
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i)
            f[i] = f[i-1] + f[i-2];
        bitset<32> bit(n);
        for (int i = 31; i >= 0; --i) {
            if (bit[i] == 0)
                continue;
            res += f[i];
            if (i + 1 <= 31 && bit[i + 1] == 1)
                return res;
        }
        return res + 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    int n, res;
    
    /**
     输入: 5
     输出: 5
     解释:
     下面是带有相应二进制表示的非负整数<= 5：
     0 : 0
     1 : 1
     2 : 10
     3 : 11
     4 : 100
     5 : 101
     其中，只有整数3违反规则（有两个连续的1），其他5个满足规则。
     */
    n = 5;
    res = 5;
    assert(res == Solution().findIntegers(n));
        
    cout << "OK~" << endl;
    
    return 0;
}
