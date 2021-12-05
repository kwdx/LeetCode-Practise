/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    int MOD = 1337;
    int dfs(int a, vector<int>& b, int u) {
        if (u == -1) return 1;
        return qpow(dfs(a, b, u - 1), 10) * qpow(a, b[u]) % MOD;
    }
    
    int qpow(int a, int b) {
        int ans = 1;
        a %= MOD;
        while (b != 0) {
            if ((b & 1) != 0) ans = ans * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }
public:
    int superPow(int a, vector<int>& b) {
        return dfs(a, b, (int)b.size() - 1);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a;
    vector<int> b;
    int res;
    
    /**
     输入：a = 2, b = [3]
     输出：8
     */
    a = 2;
    b = {3};
    res = 8;
    assert(res == Solution().superPow(a, b));
    
    /**
     输入：a = 2, b = [1,0]
     输出：1024
     */
    a = 2;
    b = {1,0};
    res = 1024;
    assert(res == Solution().superPow(a, b));
    
    /**
     输入：a = 1, b = [4,3,3,8,5,2]
     输出：1
     */
    a = 1;
    b = {4,3,3,8,5,2};
    res = 1;
    assert(res == Solution().superPow(a, b));
    
    /**
     输入：a = 2147483647, b = [2,0,0]
     输出：1198
     */
    a = 2147483647;
    b = {2,0,0};
    res = 1198;
    assert(res == Solution().superPow(a, b));

    cout << "OK~" << endl;

    return 0;
}
