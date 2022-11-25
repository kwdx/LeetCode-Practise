/*
 * @lc app=leetcode.cn id=809 lang=cpp
 *
 * [809] 情感丰富的文字
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (string& t : words)
            ans += check(s, t);
        return ans;
    }
    
    int check(string& s, string& t) {
        int m = (int)s.size(), n = (int)t.size();
        if (n > m) return 0;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s[i] != t[j]) return 0;
            int k = i;
            while (k < m && s[k] == s[i]) ++k;
            int c1 = k - i;
            i = k;
            k = j;
            while (k < n && t[k] == t[j]) ++k;
            int c2 = k - j;
            j = k;
            if (c1 < c2 || (c1 < 3 && c1 != c2)) return 0;
        }
        return i == m && j == n;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    vector<string> words;
    int res;
    
    /**
     输入：
     S = "heeellooo"
     words = ["hello", "hi", "helo"]
     输出：1
     解释：
     我们能通过扩张 "hello" 的 "e" 和 "o" 来得到 "heeellooo"。
     我们不能通过扩张 "helo" 来得到 "heeellooo" 因为 "ll" 的长度小于 3 。
     */
    s = "heeellooo";
    words = {"hello", "hi", "helo"};
    res = 1;
    assert(res == Solution().expressiveWords(s, words));
    
    cout << "OK~" << endl;
    
    return 0;
}
