/*
 * @lc app=leetcode.cn id=1175 lang=cpp
 *
 * [1175] 质数排列
 */

#include <iostream>

using namespace std;

// @lc code=start
const int MOD = 1e9 + 7;

class Solution {
public:
    int numPrimeArrangements(int n) {
        int primes = 0;
        for (int i = 1; i <= n; ++i) {
            if (isPrime(i)) {
                ++primes;
            }
        }
        return (factorial(primes) * factorial(n - primes)) % MOD;
    }
    
    bool isPrime(int num) {
        if (num == 1) {
            return false;
        }
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    long factorial(int num) {
        long ans = 1;
        for (int i = 1; i <= num; i++) {
            ans *= i;
            ans %= MOD;
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
     输入：n = 5
     输出：12
     解释：举个例子，[1,2,5,4,3] 是一个有效的排列，但 [5,2,3,4,1] 不是，因为在第二种情况里质数 5 被错误地放在索引为 1 的位置上。
     */
    n = 5;
    res = 12;
    assert(res == Solution().numPrimeArrangements(n));
    
    /**
     输入：n = 100
     输出：682289015
     */
    n = 100;
    res = 682289015;
    assert(res == Solution().numPrimeArrangements(n));
    
    cout << "OK~" << endl;
    
    return 0;
}
