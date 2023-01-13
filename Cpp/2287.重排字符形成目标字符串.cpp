/*
 * @lc app=leetcode.cn id=2287 lang=cpp
 *
 * [2287] 重排字符形成目标字符串
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> sCounts, targetCounts;
        int n = (int)s.size(), m = (int)target.size();
        for (int i = 0; i < m; ++i) {
            targetCounts[target[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            if (targetCounts.count(s[i])) {
                sCounts[s[i]]++;
            }
        }
        int ans = INT_MAX;
        for (auto &[c, count] : targetCounts) {
            int totalCount = sCounts[c];
            ans = min(ans, totalCount / count);
            if (ans == 0) {
                return 0;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    string target;
    int res;

    /**
     输入：s = "ilovecodingonleetcode", target = "code"
     输出：2
     解释：
     对于 "code" 的第 1 个副本，选取下标为 4 、5 、6 和 7 的字符。
     对于 "code" 的第 2 个副本，选取下标为 17 、18 、19 和 20 的字符。
     形成的字符串分别是 "ecod" 和 "code" ，都可以重排为 "code" 。
     可以形成最多 2 个 "code" 的副本，所以返回 2 。
     */
    s = "ilovecodingonleetcode";
    target = "code";
    res = 2;
    assert(res == Solution().rearrangeCharacters(s, target));
    
    /**
     输入：s = "abcba", target = "abc"
     输出：1
     解释：
     选取下标为 0 、1 和 2 的字符，可以形成 "abc" 的 1 个副本。
     可以形成最多 1 个 "abc" 的副本，所以返回 1 。
     注意，尽管下标 3 和 4 分别有额外的 'a' 和 'b' ，但不能重用下标 2 处的 'c' ，所以无法形成 "abc" 的第 2 个副本。
     */
    s = "abcba";
    target = "abc";
    res = 1;
    assert(res == Solution().rearrangeCharacters(s, target));
    
    /**
     输入：s = "abbaccaddaeea", target = "aaaaa"
     输出：1
     解释：
     选取下标为 0 、3 、6 、9 和 12 的字符，可以形成 "aaaaa" 的 1 个副本。
     可以形成最多 1 个 "aaaaa" 的副本，所以返回 1 。
     */
    s = "abbaccaddaeea";
    target = "aaaaa";
    res = 1;
    assert(res == Solution().rearrangeCharacters(s, target));
    
    cout << "OK~" << endl;
    
    return 0;
}
