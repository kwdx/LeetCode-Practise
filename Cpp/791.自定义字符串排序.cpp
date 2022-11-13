/*
 * @lc app=leetcode.cn id=791 lang=cpp
 *
 * [791] 自定义字符串排序
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> cnts(26, 0);
        for (char& c : s) {
            cnts[c - 'a'] += 1;
        }
        string ans;
        for (char& c : order) {
            while (cnts[c - 'a']-- > 0) {
                ans.push_back(c);
            }
        }
        for (int i = 0; i < 26; ++i) {
            while (cnts[i]-- > 0) {
                ans.push_back('a' + i);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string order;
    string s;
    string res;
    
    /**
     输入: order = "cba", s = "abcd"
     输出: "cbad"
     解释:
     “a”、“b”、“c”是按顺序出现的，所以“a”、“b”、“c”的顺序应该是“c”、“b”、“a”。
     因为“d”不是按顺序出现的，所以它可以在返回的字符串中的任何位置。“dcba”、“cdba”、“cbda”也是有效的输出。
     */
    order = "cba";
    s = "abcd";
    res = "cbad";
    assert(res == Solution().customSortString(order, s));
    
    /**
     输入: order = "cbafg", s = "abcd"
     输出: "cbad"
     */
    order = "cbafg";
    s = "abcd";
    res = "cbad";
    assert(res == Solution().customSortString(order, s));
    
    cout << "OK~" << endl;
    
    return 0;
}
