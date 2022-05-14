/*
 * @lc app=leetcode.cn id=691 lang=cpp
 *
 * [691] 贴纸拼词
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int m = target.size();
        vector<int> dp(1 << m, -1);
        dp[0] = 0;
        function<int(int)> helper = [&](int mask) {
            if (dp[mask] != -1) {
                return dp[mask];
            }
            dp[mask] = m + 1;
            for (auto & sticker : stickers) {
                int left = mask;
                vector<int> cnt(26);
                for (char & c : sticker) {
                    cnt[c - 'a']++;
                }
                for (int i = 0; i < m; i++) {
                    if ((mask >> i & 1) && cnt[target[i] - 'a'] > 0) {
                        cnt[target[i] - 'a']--;
                        left ^= 1 << i;
                    }
                }
                if (left < mask) {
                    dp[mask] = min(dp[mask], helper(left) + 1);
                }
            }
            return dp[mask];
        };
        int res = helper((1 << m) - 1);
        return res > m ? -1 : res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> stickers;
    string target;
    int res;
    
    /**
     输入： stickers = ["with","example","science"], target = "thehat"
     输出：3
     解释：
     我们可以使用 2 个 "with" 贴纸，和 1 个 "example" 贴纸。
     把贴纸上的字母剪下来并重新排列后，就可以形成目标 “thehat“ 了。
     此外，这是形成目标字符串所需的最小贴纸数量。
     */
    stickers = {"with","example","science"};
    target = "thehat";
    res = 3;
    assert(res == Solution().minStickers(stickers, target));
    
    /**
     输入：stickers = ["notice","possible"], target = "basicbasic"
     输出：-1
     解释：我们不能通过剪切给定贴纸的字母来形成目标“basicbasic”。
     */
    stickers = {"notice","possible"};
    target = "basicbasic";
    res = -1;
    assert(res == Solution().minStickers(stickers, target));
    
    cout << "OK~" << endl;
    
    return 0;
}
