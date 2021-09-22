/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int preLen = 0;
        for (char & c : s) {
            if (c == ' ') {
                if (len > 0) {
                    preLen = len;
                    len = 0;
                }
            } else {
                ++len;
            }
        }
        return len > 0 ? len : preLen;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string s;
    int res;
    
    /**
     输入：s = "Hello World"
     输出：5
     */
    s = "Hello World";
    res = 5;
    assert(res == Solution().lengthOfLastWord(s));
    
    /**
     输入：s = "   fly me   to   the moon  "
     输出：4
     */
    s = "   fly me   to   the moon  ";
    res = 4;
    assert(res == Solution().lengthOfLastWord(s));
    
    /**
     输入：s = "luffy is still joyboy"
     输出：6
     */
    s = "luffy is still joyboy";
    res = 6;
    assert(res == Solution().lengthOfLastWord(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
