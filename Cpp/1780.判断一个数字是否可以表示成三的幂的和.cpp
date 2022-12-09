/*
 * @lc app=leetcode.cn id=1780 lang=cpp
 *
 * [1780] 判断一个数字是否可以表示成三的幂的和
 */

#include <iostream>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n != 0) {
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
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
     输入：n = 12
     输出：true
     解释：12 = 31 + 32
     */
    n = 12;
    res = true;
    assert(res == Solution().checkPowersOfThree(n));
    
    /**
     输入：n = 91
     输出：true
     解释：91 = 30 + 32 + 34
     */
    n = 91;
    res = true;
    assert(res == Solution().checkPowersOfThree(n));
    
    /**
     输入：n = 21
     输出：false
     */
    n = 21;
    res = false;
    assert(res == Solution().checkPowersOfThree(n));

    cout << "OK~" << endl;
    
    return 0;
}
