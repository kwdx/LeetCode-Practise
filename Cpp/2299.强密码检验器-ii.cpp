/*
 * @lc app=leetcode.cn id=2299 lang=cpp
 *
 * [2299] 强密码检验器 II
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = (int)password.size();
        if (n < 8) {
            return false;
        }
        int kind = 0;
        for (int i = 0; i < n; ++i) {
            char c = password[i];
            if (i != 0 && c == password[i - 1]) {
                return false;
            }
            if (c >= 'a' && c <= 'z') {
                kind |= 1 << 0;
            } else if (c >= 'A' && c <= 'Z') {
                kind |= 1 << 1;
            } else if (c >= '0' && c <= '9') {
                kind |= 1 << 2;
            } else {
                kind |= 1 << 3;
            }
        }
        return (kind ^ 0xF) == 0;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string password;
    bool res;

    /**
     输入：password = "IloveLe3tcode!"
     输出：true
     解释：密码满足所有的要求，所以我们返回 true 。
     */
    password = "IloveLe3tcode!";
    res = true;
    assert(res == Solution().strongPasswordCheckerII(password));
    
    /**
     输入：password = "Me+You--IsMyDream"
     输出：false
     解释：密码不包含数字，且包含 2 个连续相同的字符。所以我们返回 false 。
     */
    password = "Me+You--IsMyDream";
    res = false;
    assert(res == Solution().strongPasswordCheckerII(password));
    
    /**
     输入：password = "1aB!"
     输出：false
     解释：密码不符合长度要求。所以我们返回 false 。
     */
    password = "1aB!";
    res = false;
    assert(res == Solution().strongPasswordCheckerII(password));
    
    cout << "OK~" << endl;
    
    return 0;
}
