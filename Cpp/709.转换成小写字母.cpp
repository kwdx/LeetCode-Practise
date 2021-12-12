/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string toLowerCase(string s) {
        string ans;
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {
                ans += c + 32;
            } else {
                ans += c;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    string res;
    
    /**
     输入：s = "Hello"
     输出："hello"
     */
    s = "Hello";
    res = "hello";
    assert(res == Solution().toLowerCase(s));
    
    /**
     输入：s = "here"
     输出："here"
     */
    s = "here";
    res = "here";
    assert(res == Solution().toLowerCase(s));
    
    /**
     输入：s = "LOVELY"
     输出："lovely"
     */
    s = "LOVELY";
    res = "lovely";
    assert(res == Solution().toLowerCase(s));

    cout << "OK~" << endl;

    return 0;
}
