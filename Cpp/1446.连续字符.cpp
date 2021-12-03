/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++cnt;
            } else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        return max(ans, cnt);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int res;
    
    /**
     输入：s = "leetcode"
     输出：2
     解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
     */
    s = "leetcode";
    res = 2;
    assert(res == Solution().maxPower(s));
    
    /**
     输入：s = "abbcccddddeeeeedcba"
     输出：5
     解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
     */
    s = "abbcccddddeeeeedcba";
    res = 5;
    assert(res == Solution().maxPower(s));
    
    /**
     输入：s = "triplepillooooow"
     输出：5
     */
    s = "triplepillooooow";
    res = 5;
    assert(res == Solution().maxPower(s));
    
    /**
     输入：s = "hooraaaaaaaaaaay"
     输出：11
     */
    s = "hooraaaaaaaaaaay";
    res = 11;
    assert(res == Solution().maxPower(s));
    
    /**
     输入：s = "tourist"
     输出：1
     */
    s = "tourist";
    res = 1;
    assert(res == Solution().maxPower(s));

    cout << "OK~" << endl;

    return 0;
}
