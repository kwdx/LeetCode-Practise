/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        string tmp;
        for (int i = 2; i <= n; ++i) {
            int num = 1;
            for (int j = 1; j < ans.size(); ++j) {
                if (ans[j] != ans[j - 1]) {
                    tmp += to_string(num) + ans[j - 1];
                    num = 1;
                } else {
                    ++num;
                }
            }
            ans = tmp + to_string(num) + ans.back();
            tmp = "";
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    int n;
    string res;
    
    /**
     输入：n = 1
     输出："1"
     解释：这是一个基本样例。
     */
    n = 1;
    res = "1";
    assert(res == Solution().countAndSay(n));
    
    /**
     输入：n = 4
     输出："1211"
     解释：
     countAndSay(1) = "1"
     countAndSay(2) = 读 "1" = 一 个 1 = "11"
     countAndSay(3) = 读 "11" = 二 个 1 = "21"
     countAndSay(4) = 读 "21" = 一 个 2 + 一 个 1 = "12" + "11" = "1211"
     */
    n = 4;
    res = "1211";
    assert(res == Solution().countAndSay(n));
    
    assert("111221" == Solution().countAndSay(5));
    
    cout << "OK~" << endl;
    
    return 0;
}
