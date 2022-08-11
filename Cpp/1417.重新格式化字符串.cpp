/*
 * @lc app=leetcode.cn id=1417 lang=cpp
 *
 * [1417] 重新格式化字符串
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string reformat(string s) {
        int digits = 0;
        for (auto& c : s) {
            if (isdigit(c)) ++digits;
        }
        int alphas = (int)s.size() - digits;
        
        if (abs(digits - alphas) > 1) {
            return "";
        }
        bool flag = digits > alphas;
        for (int i = 0, j = 1; i < s.size(); i += 2) {
            if (isdigit(s[i]) != flag) {
                while (isdigit(s[j]) != flag) {
                    j += 2;
                }
                swap(s[i], s[j]);
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
     输入：s = "a0b1c2"
     输出："0a1b2c"
     解释："0a1b2c" 中任意两个相邻字符的类型都不同。 "a0b1c2", "0a1b2c", "0c2a1b" 也是满足题目要求的答案。
     */
    s = "a0b1c2";
    res = "a0b1c2";
    assert(res == Solution().reformat(s));
    
    /**
     输入：s = "leetcode"
     输出：""
     解释："leetcode" 中只有字母，所以无法满足重新格式化的条件。
     */
    s = "leetcode";
    res = "";
    assert(res == Solution().reformat(s));
    
    /**
     输入：s = "1229857369"
     输出：""
     解释："1229857369" 中只有数字，所以无法满足重新格式化的条件。
     */
    s = "1229857369";
    res = "";
    assert(res == Solution().reformat(s));
    
    /**
     输入：s = "covid2019"
     输出："c2o0v1i9d"
     */
    s = "covid2019";
    res = "c0v9d2o1i";
    assert(res == Solution().reformat(s));
    
    /**
     输入：s = "ab123"
     输出："1a2b3"
     */
    s = "ab123";
    res = "2b1a3";
    assert(res == Solution().reformat(s));

    cout << "OK~" << endl;
    
    return 0;
}
