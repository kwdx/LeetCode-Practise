/*
 * @lc app=leetcode.cn id=686 lang=cpp
 *
 * [686] 重复叠加字符串匹配
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string ab = "";
        int ans = 0;
        while (ab.size() < b.size()) {
            ab.append(a);
            ++ans;
        }
        ab.append(a);
        int idx = KMP(ab, b);
        if (idx == -1) return -1;
        return idx + b.size() > a.size() * ans ? ans + 1 : ans;
    }
    
    int KMP(const string& s, const string& p) {
        vector<int> next = getNext(p);
        int i = 0, j = 0;
        for (; i < s.size(); ++i) {
            if (j >= p.size()) break;
            while (j > 0 && s[i] != p[j]) {
                j = next[j - 1];
            }
            if (s[i] == p[j]) ++j;
        }
        if (j >= p.size()) return i - j;
        return -1;
    }
    
    vector<int> getNext(const string& p){
        int n = (int)p.size();
        vector<int> next(n, 0);
        for (int i = 1, j = 0; i < n; ++i) {
            while (j > 0 && p[j] != p[i]) j = next[j - 1];
            if (p[j] == p[i]) {
                next[i] = ++j;
            }
        }
        return next;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string a, b;
    int res;
    
    /**
     输入：a = "abcd", b = "cdabcdab"
     输出：3
     解释：a 重复叠加三遍后为 "abcdabcdabcd", 此时 b 是其子串。
     */
    a = "abcd";
    b = "cdabcdab";
    res = 3;
    assert(res == Solution().repeatedStringMatch(a, b));
    
    /**
     输入：a = "a", b = "aa"
     输出：2
     */
    a = "a";
    b = "aa";
    res = 2;
    assert(res == Solution().repeatedStringMatch(a, b));
    
    /**
     输入：a = "a", b = "a"
     输出：1
     */
    a = "a";
    b = "a";
    res = 1;
    assert(res == Solution().repeatedStringMatch(a, b));
    
    /**
     输入：a = "abc", b = "wxyz"
     输出：-1
     */
    a = "abc";
    b = "wxyz";
    res = -1;
    assert(res == Solution().repeatedStringMatch(a, b));

    cout << "OK~" << endl;

    return 0;
}
