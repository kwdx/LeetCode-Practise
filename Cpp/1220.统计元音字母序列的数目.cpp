/*
 * @lc app=leetcode.cn id=1220 lang=cpp
 *
 * [1220] 统计元音字母序列的数目
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
private:
    int MOD = (int)1e9+7;
public:
    int countVowelPermutation(int n) {
        long f[n][5];
        for (int i = 0; i < 5; ++i) {
            f[0][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            f[i][0] = f[i - 1][1] % MOD;
            f[i][1] = (f[i - 1][0] + f[i - 1][2]) % MOD;
            f[i][2] = (f[i - 1][0] + f[i - 1][1] + f[i - 1][3] + f[i - 1][4]) % MOD;
            f[i][3] = (f[i - 1][2] + f[i - 1][4]) % MOD;
            f[i][4] = f[i - 1][0] % MOD;
        }
        long ans = 0;
        for (int i = 0; i < 5; ++i) {
            ans += f[n - 1][i];
        }
        return (int)(ans % MOD);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int res;
    
    /**
     输入：n = 1
     输出：5
     解释：所有可能的字符串分别是："a", "e", "i" , "o" 和 "u"。
     */
    n = 1;
    res = 5;
    assert(res == Solution().countVowelPermutation(n));
    
    /**
     输入：n = 2
     输出：10
     解释：所有可能的字符串分别是："ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" 和 "ua"。
     */
    n = 2;
    res = 10;
    assert(res == Solution().countVowelPermutation(n));
    
    /**
     输入：n = 5
     输出：68
     */
    n = 5;
    res = 68;
    assert(res == Solution().countVowelPermutation(n));

    cout << "OK~" << endl;

    return 0;
}
