/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = (int)s.size();
        vector<int> ans(n + 1);
        int l = 0, r = n, idx = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I') {
                ans[idx++] = l++;
            } else {
                ans[idx++] = r--;
            }
        }
        ans[idx] = l;
        return ans;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...

    string s;
    vector<int> res;
    
    /**
     输入：s = "IDID"
     输出：[]
     */
    s = "IDID";
    res = {0,4,1,3,2};
    assert(res == Solution().diStringMatch(s));
    
    /**
     输入：s = "III"
     输出：[0,1,2,3]
     */
    s = "III";
    res = {0,1,2,3};
    assert(res == Solution().diStringMatch(s));
    
    /**
     输入：s = "DDI"
     输出：[3,2,0,1]
     */
    s = "DDI";
    res = {3,2,0,1};
    assert(res == Solution().diStringMatch(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
