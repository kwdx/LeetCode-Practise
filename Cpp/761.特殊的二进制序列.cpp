/*
 * @lc app=leetcode.cn id=761 lang=cpp
 *
 * [761] 特殊的二进制序列
 */

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) return s;
        
        int cnt = 0, left = 0;
        vector<string> subs;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                ++cnt;
            }
            else {
                --cnt;
                if (cnt == 0) {
                    subs.push_back("1" + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0");
                    left = i + 1;
                }
            }
        }

        sort(subs.begin(), subs.end(), greater<string>{});
        string ans = accumulate(subs.begin(), subs.end(), ""s);
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    string res;
    
    /**
     输入: S = "11011000"
     输出: "11100100"
     解释:
     将子串 "10" （在S[1]出现） 和 "1100" （在S[3]出现）进行交换。
     这是在进行若干次操作后按字典序排列最大的结果。
     */
    s = "11011000";
    res = "11100100";
    assert(res == Solution().makeLargestSpecial(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
