/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int score = 0;
        for (char c : s) {
            score += c == '(' ? 1 : -1;
            if (score < 0) {
                score = 0;
                ans += 1;
            }
        }
        return score + ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int res;
    
    /**
     输入：s = "())"
     输出：1
     */
    s = "())";
    res = 1;
    assert(res == Solution().minAddToMakeValid(s));
    
    /**
     输入：s = "((("
     输出：3
     */
    s = "(((";
    res = 3;
    assert(res == Solution().minAddToMakeValid(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
