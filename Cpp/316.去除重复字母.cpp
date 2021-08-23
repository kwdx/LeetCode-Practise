/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        int count[256] = {0};
        for (char c : s) {
            count[c]++;
        }
        bool inStack[256] = {false};
        for (char c : s) {
            count[c]--;

            if (inStack[c]) continue;

            while (!st.empty() && st.top() > c) {
                if (count[st.top()] == 0) break;
                inStack[st.top()] = false;
                st.pop();
            }
            st.push(c);
            inStack[c] = true;
        }
        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string s, res;

    /**
     输入：s = "bcabc"
     输出："abc"
     */
    s = "bcabc";
    res = "abc";
    assert(res == Solution().removeDuplicateLetters(s));

    /**
     输入：s = "cbacdcbc"
     输出："acdb"
     */
    s = "cbacdcbc";
    res = "acdb";
    assert(res == Solution().removeDuplicateLetters(s));

    cout << "OK~" << endl;

    return 0;
}
