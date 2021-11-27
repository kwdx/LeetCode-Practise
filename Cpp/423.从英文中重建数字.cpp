/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> c;
        for (char ch : s) {
            ++c[ch];
        }
        
        vector<int> cnt(10);
        cnt[0] = c['z'];
        cnt[2] = c['w'];
        cnt[4] = c['u'];
        cnt[5] = c['f'] - cnt[4];
        cnt[6] = c['x'];
        cnt[7] = c['s'] - cnt[6];
        cnt[8] = c['g'];
        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];
        cnt[3] = c['h'] - cnt[8];
        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];
        
        string ans;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += char(i + '0');
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    string res;
    
    /**
     输入：s = "owoztneoer"
     输出："012"
     */
    s = "owoztneoer";
    res = "012";
    assert(res == Solution().originalDigits(s));
    
    /**
     输入：s = "fviefuro"
     输出："45"
     */
    s = "fviefuro";
    res = "45";
    assert(res == Solution().originalDigits(s));
    
    /**
     输入：s = "nnei"
     输出："9"
     */
    s = "nnei";
    res = "9";
    assert(res == Solution().originalDigits(s));

    cout << "OK~" << endl;

    return 0;
}
