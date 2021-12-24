/*
 * @lc app=leetcode.cn id=1044 lang=cpp
 *
 * [1044] 最长重复子串
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
private:
    typedef unsigned long long ull;
    vector<ull> h, p;
    
    string check(string s, int len) {
        int n = (int)s.length();
        set<ull> sets;
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            ull hash = h[j] - h[i - 1] * p[j - i + 1];
            if (sets.count(hash))
                return s.substr(i - 1, j - i + 1);
            sets.insert(hash);
        }
        return "";
    }
public:
    string longestDupSubstring(string s) {
        int P = 1313131, n = (int)s.length();
        h.resize(n + 10, 0);
        p.resize(n + 10, 0);
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * P;
            h[i + 1] = h[i] * P + (s[i] - 'a');
        }
        string ans = "";
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            string t = check(s, mid);
            if (t.length() != 0) l = mid;
            else r = mid - 1;
            ans = t.length() > ans.length() ? t : ans;
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
     输入：s = "banana"
     输出："ana"
     */
    s = "banana";
    res = "ana";
    assert(res == Solution().longestDupSubstring(s));

    /**
     输入：s = "abcd"
     输出：""
     */
    s = "abcd";
    res = "";
    assert(res == Solution().longestDupSubstring(s));
    
    /**
     输入：s = "nnpxouomcofdjuujloanjimymadkuepightrfodmauhrsy"
     输出："ma"
     */
    s = "nnpxouomcofdjuujloanjimymadkuepightrfodmauhrsy";
    res = "ma";
    assert(res == Solution().longestDupSubstring(s));

    cout << "OK~" << endl;

    return 0;
}
