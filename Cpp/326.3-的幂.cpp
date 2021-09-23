/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
        
//        return n != 0 && (1162261467 % n == 0);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    int n;
    bool res;
        
    /**
     输入：n = 27
     输出：true
     */
    n = 27;
    res = true;
    assert(res == Solution().isPowerOfThree(n));
    
    /**
     输入：n = 0
     输出：false
     */
    n = 0;
    res = false;
    assert(res == Solution().isPowerOfThree(n));
    
    /**
     输入：n = 9
     输出：true
     */
    n = 9;
    res = true;
    assert(res == Solution().isPowerOfThree(n));
    
    /**
     输入：n = 45
     输出：false
     */
    n = 45;
    res = false;
    assert(res == Solution().isPowerOfThree(n));
    
    cout << "OK~" << endl;
    
    return 0;
}
