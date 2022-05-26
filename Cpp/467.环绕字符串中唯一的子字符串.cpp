/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 */

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);
        int k = 0;
        for (int i = 0; i < p.length(); ++i) {
            if (i && (p[i] - p[i - 1] + 26) % 26 == 1) {
                // 字符相差 1 或则 -25
                ++k;
            } else {
                k = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    string p;
    int res;
    
    /**
     输入: p = "a"
     输出: 1
     解释: 字符串 s 中只有一个"a"子字符。
     */
    p = "a";
    res = 1;
    assert(res == Solution().findSubstringInWraproundString(p));
    
    /**
     输入: p = "cac"
     输出: 2
     解释: 字符串 s 中的字符串“cac”只有两个子串“a”、“c”。.
     */
    p = "cac";
    res = 2;
    assert(res == Solution().findSubstringInWraproundString(p));
    
    /**
     输入: p = "zab"
     输出: 6
     解释: 在字符串 s 中有六个子串“z”、“a”、“b”、“za”、“ab”、“zab”。
     */
    p = "zab";
    res = 6;
    assert(res == Solution().findSubstringInWraproundString(p));

    cout << "OK~" << endl;
    
    return 0;
}
