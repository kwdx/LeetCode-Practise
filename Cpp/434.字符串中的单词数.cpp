/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int words = 0;
        int ans = 0;
        
        for (char & c : s) {
            if (c == ' ') {
                ans += words > 0 ? 1 : 0;
                words = 0;
            } else {
                ++words;
            }
        }
        
        return words > 0 ? ans + 1 : ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string s;
    int res;
    
//    /**
//     输入: "Hello, my name is John"
//     输出: 5
//     解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
//     */
//    s = "Hello, my name is John";
//    res = 5;
//    assert(res == Solution().countSegments(s));
    
    /**
     输入: "                "
     输出: 0
     */
    s = "                ";
    res = 0;
    assert(res == Solution().countSegments(s));
    cout << "OK~" << endl;
    
    return 0;
}
