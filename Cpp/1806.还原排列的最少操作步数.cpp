/*
 * @lc app=leetcode.cn id=1806 lang=cpp
 *
 * [1806] 还原排列的最少操作步数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int reinitializePermutation(int n) {
        if (n == 2) {
            return 1;
        }
        int ans = 1, pow2 = 2;
        while (pow2 != 1) {
            ans += 1;
            pow2 = pow2 * 2 % (n - 1);
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
     输入：n = 2
     输出：1
     解释：最初，perm = [0,1]
     第 1 步操作后，perm = [0,1]
     所以，仅需执行 1 步操作
     */
    n = 2;
    res = 1;
    assert(res == Solution().reinitializePermutation(n));
    
    /**
     输入：n = 4
     输出：2
     解释：最初，perm = [0,1,2,3]
     第 1 步操作后，perm = [0,2,1,3]
     第 2 步操作后，perm = [0,1,2,3]
     所以，仅需执行 2 步操作
     */
    n = 4;
    res = 2;
    assert(res == Solution().reinitializePermutation(n));
    
    /**
     输入：n = 6
     输出：4
     */
    n = 6;
    res = 4;
    assert(res == Solution().reinitializePermutation(n));

    cout << "OK~" << endl;
    
    return 0;
}
