/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = (int)s.size();
        int m = 0;
        for (auto c : s) {
            if (isalpha(c)) {
                ++m;
            }
        }
        vector<string> ans;
        for (int mask = 0; mask < (1 << m); ++mask) {
            string str;
            for (int j = 0, k = 0; j < n; ++j) {
                if (isalpha(s[j]) && (mask & (1 << k++))) {
                    str.push_back(toupper(s[j]));
                } else {
                    str.push_back(tolower(s[j]));
                }
            }
            ans.emplace_back(str);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    vector<string> res;
    
    /**
     输入：s = "a1b2"
     输出：["a1b2", "a1B2", "A1b2", "A1B2"]
     */
    s = "a1b2";
    res = {"a1b2", "a1B2", "A1b2", "A1B2"};
    sort(res.begin(), res.end());
    assert(res == Solution().letterCasePermutation(s));
    
    /**
     输入: s = "3z4"
     输出: ["3z4","3Z4"]
     */
    s = "3z4";
    res = {"3z4","3Z4"};
    sort(res.begin(), res.end());
    assert(res == Solution().letterCasePermutation(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
