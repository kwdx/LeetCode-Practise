/*
 * @lc app=leetcode.cn id=1704 lang=cpp
 *
 * [1704] 判断字符串的两半是否相似
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = (int)s.length();
        int mid = n >> 1;
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            switch (s[i]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    if (i < mid) a += 1;
                    else b += 1;
                    break;
                default:
                    break;
            }
        }
        return a == b;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    bool res;
    
    /**
     输入：s = "book"
     输出：true
     解释：a = "bo" 且 b = "ok" 。a 中有 1 个元音，b 也有 1 个元音。所以，a 和 b 相似。
     */
    s = "book";
    res = true;
    assert(res == Solution().halvesAreAlike(s));
    
    /**
     输入：s = "textbook"
     输出：false
     解释：a = "text" 且 b = "book" 。a 中有 1 个元音，b 中有 2 个元音。因此，a 和 b 不相似。
     注意，元音 o 在 b 中出现两次，记为 2 个。
     */
    s = "textbook";
    res = false;
    assert(res == Solution().halvesAreAlike(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
