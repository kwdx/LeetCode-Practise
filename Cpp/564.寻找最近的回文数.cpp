/*
 * @lc app=leetcode.cn id=564 lang=cpp
 *
 * [564] 寻找最近的回文数
 */

#include <iostream>
#include <string>
#include <set>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    string nearestPalindromic(string s) {
        int n = (int)s.size();
        long cur = atol(s.c_str());

        auto getNum = [](long k, bool isEven) {
            string str = to_string(k);
            int idx = (int)(isEven ? str.length() - 1 : str.length() - 2);
            while (idx >= 0) str.push_back(str[idx--]);
            return atol(str.c_str());
        };
        
        set<long> bucket;
        bucket.insert(pow(10, n - 1) - 1);
        bucket.insert(pow(10, n) + 1);
        long t = atol(s.substr(0, (n + 1) / 2).c_str());
        for (long i = t - 1; i <= t + 1; ++i) {
            long temp = -1;
            if (n % 2 == 0) temp = getNum(i, true);
            else temp = getNum(i, false);
            if (temp != cur) bucket.insert(temp);
        }
        
        long ans = -1;
        for (long i : bucket) {
            if (ans == -1) ans = i;
            else if (abs(i - cur) < abs(ans - cur)) ans = i;
            else if (abs(i - cur) == abs(ans - cur) && i < ans) ans = i;
        }
        return to_string(ans);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string n;
    string res;
    
    /**
     输入: n = "123"
     输出: "121"
     */
    n = "123";
    res = "121";
    assert(res == Solution().nearestPalindromic(n));
    
    /**
     输入: n = "1"
     输出: "0"
     解释: 0 和 2是最近的回文，但我们返回最小的，也就是 0。
     */
    n = "1";
    res = "0";
    assert(res == Solution().nearestPalindromic(n));

    cout << "OK~" << endl;
    
    return 0;
}
