/*
 * @lc app=leetcode.cn id=899 lang=cpp
 *
 * [899] 有序队列
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string ans = s;
            for (int i = 1; i < s.size(); ++i) {
                s.push_back(s[0]);
                s.erase(s.begin());
                if (s < ans) {
                    ans = s;
                }
            }
            return ans;
        } else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int k;
    string res;
    
    /**
     输入：s = "cba", k = 1
     输出："acb"
     解释：
     在第一步中，我们将第一个字符（“c”）移动到最后，获得字符串 “bac”。
     在第二步中，我们将第一个字符（“b”）移动到最后，获得最终结果 “acb”。
     */
    s = "cba";
    k = 1;
    res = "acb";
    assert(res == Solution().orderlyQueue(s, k));
    
    /**
     输入：s = "baaca", k = 3
     输出："aaabc"
     解释：
     在第一步中，我们将第一个字符（“b”）移动到最后，获得字符串 “aacab”。
     在第二步中，我们将第三个字符（“c”）移动到最后，获得最终结果 “aaabc”。
     */
    s = "baaca";
    k = 3;
    res = "aaabc";
    assert(res == Solution().orderlyQueue(s, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
