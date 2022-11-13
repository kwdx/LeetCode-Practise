/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
static int MOD = 1e9 + 7;
class Solution {
public:
    int numTilings(int n) {
        vector<vector<int>> f(2, vector<int>(4,0));
        f[1][0] = f[1][1] = 1;
        for (int i = 2; i <= n; ++i) {
            int a = i & 1;
            int b = (i - 1) & 1;
            f[a][0] = f[b][1];
            int cur = 0;
            for (int j = 0; j < 4; ++j) {
                cur = (cur + f[b][j]) % MOD;
            }
            f[a][1] = cur;
            f[a][2] = (f[b][0] + f[b][3]) % MOD;
            f[a][3] = (f[b][0] + f[b][2]) % MOD;
        }
        return f[n & 1][1];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int res;
    
    /**
     输入: n = 3
     输出: 5
     解释: 五种不同的方法如上所示。
     */
    n = 3;
    res = 5;
    assert(res == Solution().numTilings(n));
    
    /**
     输入: n = 1
     输出: 1
     */
    n = 1;
    res = 1;
    assert(res == Solution().numTilings(n));
    
    cout << "OK~" << endl;
    
    return 0;
}
