/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        unsigned int bit = 1;
        while (bit < num) {
            if (!(num & bit)) {
                ans |= bit;
            }
            bit <<= 1;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int num, res;
    
    /**
     输入：num = 5
     输出：2
     解释：5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。
     */
    num = 5;
    res = 2;
    assert(res == Solution().findComplement(num));
    
    /**
     输入：num = 1
     输出：0
     解释：1 的二进制表示为 1（没有前导零位），其补数为 0。所以你需要输出 0 。
     */
    num = 1;
    res = 0;
    assert(res == Solution().findComplement(num));
    
    cout << "OK~" << endl;

    return 0;
}
