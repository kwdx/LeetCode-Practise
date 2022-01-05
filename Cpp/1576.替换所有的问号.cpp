/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string modifyString(string s) {
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3 && s[i] == '?'; ++j) {
                char c = 'a' + j;
                bool ok = true;
                if (i - 1 >= 0 && s[i - 1] == c) ok = false;
                if (i + 1 < n && s[i + 1] == c) ok = false;
                if (ok) s[i] = c;
            }
        }
        return s;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    string res;
    
    /**
     输入：s = "?zs"
     输出："azs"
     解释：该示例共有 25 种解决方案，从 "azs" 到 "yzs" 都是符合题目要求的。只有 "z" 是无效的修改，因为字符串 "zzs" 中有连续重复的两个 'z' 。
     */
    s = "?zs";
    res = "azs";
    assert(res == Solution().modifyString(s));
    
    /**
     输入：s = "ubv?w"
     输出："ubvaw"
     解释：该示例共有 24 种解决方案，只有替换成 "v" 和 "w" 不符合题目要求。因为 "ubvvw" 和 "ubvww" 都包含连续重复的字符。
     */
    s = "ubv?w";
    res = "ubvaw";
    assert(res == Solution().modifyString(s));
    
    /**
     输入：s = "j?qg??b"
     输出："jaqgacb"
     */
    s = "j?qg??b";
    res = "jaqgacb";
    assert(res == Solution().modifyString(s));
    
    /**
     输入：s = "??yw?ipkj?"
     输出："acywaipkja"
     */
    s = "??yw?ipkj?";
    res = "abywaipkja";
    assert(res == Solution().modifyString(s));

    cout << "OK~" << endl;

    return 0;
}
