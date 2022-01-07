/*
 * @lc app=leetcode.cn id=1614 lang=cpp
 *
 * [1614] 括号的最大嵌套深度
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int cnt = 0;
        for (char ch : s) {
            if (ch == '(') {
                ++cnt;
            } else if (ch == ')') {
                --cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int res;
    
    /**
     输入：s = "(1+(2*3)+((8)/4))+1"
     输出：3
     解释：数字 8 在嵌套的 3 层括号中。
     */
    s = "(1+(2*3)+((8)/4))+1";
    res = 3;
    assert(res == Solution().maxDepth(s));
    
    /**
     输入：s = "(1)+((2))+(((3)))"
     输出：3
     */
    s = "(1)+((2))+(((3)))";
    res = 3;
    assert(res == Solution().maxDepth(s));
    
    /**
     输入：s = "1+(2*3)/(2-1)"
     输出：1
     */
    s = "1+(2*3)/(2-1)";
    res = 1;
    assert(res == Solution().maxDepth(s));
    
    /**
     输入：s = "1"
     输出：0
     */
    s = "1";
    res = 0;
    assert(res == Solution().maxDepth(s));

    cout << "OK~" << endl;

    return 0;
}
