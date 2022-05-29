/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string validIPAddress(string queryIP) {
        int n = (int)queryIP.size();
        if (queryIP.find(".") != -1) {
            // 可能是IPv4
            int prev = -1;
            for (int i = 0; i < 4; ++i) {
                int cur = i == 3 ? n : (int)queryIP.find('.', prev + 1);
                if (cur == string::npos) { return "Neither"; }
                if (cur - prev - 1 < 1 || cur - prev - 1 > 3) { return "Neither"; }
                int val = 0;
                for (int j = prev + 1; j < cur; ++j) {
                    if (!isdigit(queryIP[j])) { return "Neither"; }
                    val = val * 10 + (queryIP[j] - '0');
                }
                if (val > 255) { return "Neither"; }
                if (val > 0 && queryIP[prev + 1] == '0') { return "Neither"; }
                if (val == 0 && cur - prev - 1 > 1) { return "Neither"; }
                prev = cur;
            }
            return "IPv4";
        } else {
            int prev = -1;
            for (int i = 0; i < 8; ++i) {
                int cur = i == 7 ? n : (int)queryIP.find(':', prev + 1);
                if (cur == string::npos) { return "Neither"; }
                if (cur - prev - 1 < 1 || cur - prev - 1 > 4) { return "Neither"; }
                for (int j = prev + 1; j < cur; ++j) {
                    if (!isdigit(queryIP[j]) && !('a' <= tolower(queryIP[j]) && tolower(queryIP[j]) <= 'f')) {
                        return "Neither";
                    }
                }
                prev = cur;
            }
            return "IPv6";
        }
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string queryIP;
    string res;
    
    /**
     输入：queryIP = "172.16.254.1"
     输出："IPv4"
     解释：有效的 IPv4 地址，返回 "IPv4"
     */
    queryIP = "172.16.254.1";
    res = "IPv4";
    assert(res == Solution().validIPAddress(queryIP));
    
    /**
     输入：queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
     输出："IPv6"
     解释：有效的 IPv6 地址，返回 "IPv6"
     */
    queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    res = "IPv6";
    assert(res == Solution().validIPAddress(queryIP));
    
    /**
     输入：queryIP = "256.256.256.256"
     输出："Neither"
     解释：既不是 IPv4 地址，又不是 IPv6 地址
     */
    queryIP = "256.256.256.256";
    res = "Neither";
    assert(res == Solution().validIPAddress(queryIP));

    cout << "OK~" << endl;

    return 0;
}
