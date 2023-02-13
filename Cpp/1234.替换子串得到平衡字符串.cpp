/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 *
 * [1234] 替换子串得到平衡字符串
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
    class Solution {
    public:
        int idx(const char& c) {
            return c - 'A';
        }

        int balancedString(string s) {
            vector<int> cnt(26);
            for (auto c : s) {
                cnt[idx(c)]++;
            }

            int partial = (int)s.size() / 4;
            int ans = (int)s.size();
            auto check = [&]() {
                if (cnt[idx('Q')] > partial || cnt[idx('W')] > partial \
                    || cnt[idx('E')] > partial || cnt[idx('R')] > partial) {
                    return false;
                }
                return true;
            };

            if (check()) {
                return 0;
            }
            for (int l = 0, r = 0; l < s.size(); l++) {
                while (r < s.size() && !check()) {
                    cnt[idx(s[r])]--;
                    r++;
                }
                if (!check()) {
                    break;
                }
                ans = min(ans, r - l);
                cnt[idx(s[l])]++;
            }
            return ans;
        }
    };
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int res;
    
    s = "WWEQERQWQWWRWWERQWEQ";
    res = 4;
    assert(res == Solution().balancedString(s));
    
    /**
     输入：s = "QWER"
     输出：0
     解释：s 已经是平衡的了。
     */
    s = "QWER";
    res = 0;
    assert(res == Solution().balancedString(s));
    
    /**
     输入：s = "QQWE"
     输出：1
     解释：我们需要把一个 'Q' 替换成 'R'，这样得到的 "RQWE" (或 "QRWE") 是平衡的。
     */
    s = "QQWE";
    res = 1;
    assert(res == Solution().balancedString(s));
    
    /**
     输入：s = "QQQW"
     输出：2
     解释：我们可以把前面的 "QQ" 替换成 "ER"。
     */
    s = "QQQW";
    res = 2;
    assert(res == Solution().balancedString(s));
    
    /**
     输入：s = "QQQQ"
     输出：3
     解释：我们可以替换后 3 个 'Q'，使 s = "QWER"。
     */
    s = "QQQQ";
    res = 3;
    assert(res == Solution().balancedString(s));

    cout << "OK~" << endl;
    
    return 0;
}
