/*
 * @lc app=leetcode.cn id=1624 lang=cpp
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        vector<int> pres(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            int pre = pres[idx];
            if (pre == -1) {
                pres[idx] = i;
            } else {
                ans = max(ans, i - pre - 1);
            }
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
     输入：s = "aa"
     输出：0
     解释：最优的子字符串是两个 'a' 之间的空子字符串。
     */
    s = "aa";
    res = 0;
    assert(res == Solution().maxLengthBetweenEqualCharacters(s));
    
    /**
     输入：s = "abca"
     输出：2
     解释：最优的子字符串是 "bc" 。
     */
    s = "abca";
    res = 2;
    assert(res == Solution().maxLengthBetweenEqualCharacters(s));
    
    /**
     输入：s = "cbzxy"
     输出：-1
     解释：s 中不存在出现出现两次的字符，所以返回 -1 。
     */
    s = "cbzxy";
    res = -1;
    assert(res == Solution().maxLengthBetweenEqualCharacters(s));
    
    /**
     输入：s = "cabbac"
     输出：4
     解释：最优的子字符串是 "abba" ，其他的非最优解包括 "bb" 和 "" 。
     */
    s = "cabbac";
    res = 4;
    assert(res == Solution().maxLengthBetweenEqualCharacters(s));

    cout << "OK~" << endl;
    
    return 0;
}
