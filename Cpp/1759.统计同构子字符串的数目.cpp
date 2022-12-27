/*
 * @lc app=leetcode.cn id=1759 lang=cpp
 *
 * [1759] 统计同构子字符串的数目
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
private:
    long long MOD = 1e9 + 7;
public:
    int countHomogenous(string s) {
        long long ans = 0;
        char prev = s[0];
        long long cnt = 0;
        for (auto c : s) {
            if (c == prev) {
                ++cnt;
            } else {
                ans += (cnt + 1) * cnt / 2 % MOD;
                cnt = 1;
                prev = c;
            }
        }
        ans += (cnt + 1) * cnt / 2 % MOD;
        return (int)(ans % MOD);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int res;
    
    /**
     输入：s = "abbcccaa"
     输出：13
     解释：同构子字符串如下所列：
     "a"   出现 3 次。
     "aa"  出现 1 次。
     "b"   出现 2 次。
     "bb"  出现 1 次。
     "c"   出现 3 次。
     "cc"  出现 2 次。
     "ccc" 出现 1 次。
     3 + 1 + 2 + 1 + 3 + 2 + 1 = 13
     */
    s = "abbcccaa";
    res = 13;
    assert(res == Solution().countHomogenous(s));
    
    /**
     输入：s = "xy"
     输出：2
     解释：同构子字符串是 "x" 和 "y" 。
     */
    s = "xy";
    res = 2;
    assert(res == Solution().countHomogenous(s));
    
    /**
     输入：s = "zzzzz"
     输出：15
     */
    s = "zzzzz";
    res = 15;
    assert(res == Solution().countHomogenous(s));

    cout << "OK~" << endl;
    
    return 0;
}
