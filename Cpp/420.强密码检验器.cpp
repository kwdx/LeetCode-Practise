/*
 * @lc app=leetcode.cn id=420 lang=cpp
 *
 * [420] 强密码检验器
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = (int)password.size();
        int A = 0, B = 0, C = 0;
        for (auto &c : password) {
            if (c >= 'a' && c < 'z') A = 1;
            else if (c >= 'A' && c <= 'Z') B = 1;
            else C = 1;
        }
        
        int m = A + B + C;
        if (n < 6) {
            return max(6 - n, 3 - m);
        } else if (n <= 20) {
            int ans = 0;
            for (int i = 0; i < n; ) {
                int j = i;
                while (j < n && password[j] == password[i]) ++j;
                int cnt = j - i;
                if (cnt >= 3) ans += cnt / 3;
                i = j;
            }
            return max(ans, 3 - m);
        } else {
            int ans = 0;
            int cnts[3] = {0, 0, 0};
            for (int i = 0; i < n; ) {
                int j = i;
                while (j < n && password[j] == password[i]) ++j;
                int cnt = j - i;
                if (cnt >= 3) {
                    ans += cnt / 3;
                    ++cnts[cnt % 3];
                }
                i = j;
            }
            int base = n - 20, cur = base;
            for (int i = 0; i < 3; ++i) {
                if (i == 2) cnts[i] = ans;
                if (cnts[i] != 0 && cur > 0) {
                    int t = min(cnts[i] * (i + 1), cur);
                    cur -= t;
                    ans -= t / (i + 1);
                }
            }
            return base + max(ans, 3 - m);
        }
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string password;
    int res;
    
    /**
     输入：password = "a"
     输出：5
     */
    password = "a";
    res = 5;
    assert(res == Solution().strongPasswordChecker(password));
    
    /**
     输入：password = "aA1"
     输出：3
     */
    password = "aA1";
    res = 3;
    assert(res == Solution().strongPasswordChecker(password));
    
    /**
     输入：password = "1337C0d3"
     输出：0
     */
    password = "1337C0d3";
    res = 0;
    assert(res == Solution().strongPasswordChecker(password));
    
    cout << "OK~" << endl;
    
    return 0;
}
