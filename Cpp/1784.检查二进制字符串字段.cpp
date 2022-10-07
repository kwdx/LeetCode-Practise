/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 *
 * [1784] 检查二进制字符串字段
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = (int)s.length();
        int cnt = 0, idx = 0;
        while (idx < n && cnt <= 1) {
            while (idx < n && s[idx] == '0')
                ++idx;
            if (idx < n) {
                while (idx < n && s[idx] == '1')
                    ++idx;
                ++cnt;
            }
        }
        return cnt <= 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    bool res;
    
    /**
     输入：s = "1001"
     输出：false
     解释：由连续若干个 '1' 组成的字段数量为 2，返回 false
     */
    s = "1001";
    res = false;
    assert(res == Solution().checkOnesSegment(s));
    
    /**
     输入：s = "110"
     输出：true
     */
    s = "110";
    res = true;
    assert(res == Solution().checkOnesSegment(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
