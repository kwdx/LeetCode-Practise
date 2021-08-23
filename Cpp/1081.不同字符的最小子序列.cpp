/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        int count[256] = {0};
        for (char c : s) {
            count[c]++;
        }

        stack<char> st;
        bool inStack[256] = {false};

        for (char c : s) {
            count[c]--;

            if (inStack[c]) continue;

            while (!st.empty() && st.top() > c) {
                if (count[st.top()] == 0) break;

                inStack[st.top()] = false;
                st.pop();
            }

            inStack[c] = true;
            st.push(c);
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
    assert(res == Solution().smallestSubsequence(s));

    /**
     输入：s = "cbacdcbc"
     输出："acdb"
     */
    s = "cbacdcbc";
    res = "acdb";
    assert(res == Solution().smallestSubsequence(s));

    cout << "OK~" << endl;

    return 0;
}
