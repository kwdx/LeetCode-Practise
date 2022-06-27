/*
 * @lc app=leetcode.cn id=522 lang=cpp
 *
 * [522] 最长特殊序列 II
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = (int)strs.size();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int m = (int)strs[i].size();
            if (m <= ans) continue;
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (isSub(strs[i], strs[j])) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans = (int)strs[i].size();
        }
        return ans;
    }
    
    bool isSub(string a, string b) {  // 判断 a 是否是 b 子串
        int idx1 = 0, idx2 = 0;
        while (idx1 < a.size() && idx2 < b.size()) {
            if (a[idx1] == b[idx2]) {
                ++idx1;
            }
            ++idx2;
        }
        return idx1 == a.size();
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> strs;
    int res;
    
    strs = {"aabbcc", "aabbcc","cb"};
    res = 2;
    assert(res == Solution().findLUSlength(strs));
    
    /**
     输入: strs = ["aba","cdc","eae"]
     输出: 3
     */
    strs = {"aba","cdc","eae"};
    res = 3;
    assert(res == Solution().findLUSlength(strs));
    
    /**
     输入: strs = ["aaa","aaa","aa"]
     输出: -1
     */
    strs = {"aaa","aaa","aa"};
    res = -1;
    assert(res == Solution().findLUSlength(strs));
    
    cout << "OK~" << endl;
    
    return 0;
}
