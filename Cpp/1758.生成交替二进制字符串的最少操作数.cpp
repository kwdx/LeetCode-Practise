/*
 * @lc app=leetcode.cn id=1758 lang=cpp
 *
 * [1758] 生成交替二进制字符串的最少操作数
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != ('0' + i % 2)) {
                ans += 1;
            }
        }
        return min(ans, n - ans);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int res;
    
    /**
     输入：s = "0100"
     输出：1
     解释：如果将最后一个字符变为 '1' ，s 就变成 "0101" ，即符合交替字符串定义。
     */
    s = "0100";
    res = 1;
    assert(res == Solution().minOperations(s));
    
    /**
     输入：s = "10"
     输出：0
     解释：s 已经是交替字符串。
     */
    s = "10";
    res = 0;
    assert(res == Solution().minOperations(s));
    
    /**
     输入：s = "1111"
     输出：2
     解释：需要 2 步操作得到 "0101" 或 "1010" 。
     */
    s = "1111";
    res = 2;
    assert(res == Solution().minOperations(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
