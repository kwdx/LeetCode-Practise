/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int dp0 = 0, dp1 = 0;
        for (char c : s) {
            int dp0New = dp0, dp1New = min(dp0, dp1);
            if (c == '1') {
                ++dp0New;
            } else {
                ++dp1New;
            }
            dp0 = dp0New;
            dp1 = dp1New;
        }
        return min(dp0, dp1);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int res;
    
    /**
     输入：s = "00110"
     输出：1
     解释：翻转最后一位得到 00111.
     */
    s = "00110";
    res = 1;
    assert(res == Solution().minFlipsMonoIncr(s));
    
    /**
     输入：s = "010110"
     输出：2
     解释：翻转得到 011111，或者是 000111。
     */
    s = "010110";
    res = 2;
    assert(res == Solution().minFlipsMonoIncr(s));
    
    /**
     输入：s = "00011000"
     输出：2
     解释：翻转得到 00000000。
     */
    s = "00011000";
    res = 2;
    assert(res == Solution().minFlipsMonoIncr(s));

    cout << "OK~" << endl;
    
    return 0;
}
