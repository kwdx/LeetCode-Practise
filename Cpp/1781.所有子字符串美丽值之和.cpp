/*
 * @lc app=leetcode.cn id=1781 lang=cpp
 *
 * [1781] 所有子字符串美丽值之和
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            vector<int> cnt(26);
            int maxFreq = 0;
            for (int j = i; j < n; ++j) {
                ++cnt[s[j] - 'a'];
                maxFreq = max(maxFreq, cnt[s[j] - 'a']);
                int minFreq = n;
                for (int k = 0; k < 26; ++k) {
                    if (cnt[k] > 0) {
                        minFreq = min(minFreq, cnt[k]);
                    }
                }
                ans += maxFreq - minFreq;
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
     输入：s = "aabcb"
     输出：5
     解释：美丽值不为零的字符串包括 ["aab","aabc","aabcb","abcb","bcb"] ，每一个字符串的美丽值都为 1 。
     */
    s = "aabcb";
    res = 5;
    assert(res == Solution().beautySum(s));
    
    /**
     输入：s = "aabcbaa"
     输出：17
     */
    s = "aabcbaa";
    res = 17;
    assert(res == Solution().beautySum(s));

    cout << "OK~" << endl;
    
    return 0;
}
