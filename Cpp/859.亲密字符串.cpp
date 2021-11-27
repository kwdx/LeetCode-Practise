/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int n = (int)s.size();
        if (n < 2) return false;
        
        if (s == goal) {
            vector<int> count(26);
            for (int i = 0; i < n; ++i) {
                ++count[s[i] - 'a'];
                if (count[s[i] - 'a'] > 1) {
                    return true;
                }
            }
            return false;
        } else {
            int left = -1, right = -1;
            for (int i = 0; i < n; ++i) {
                if (s[i] != goal[i]) {
                    if (left == -1) {
                        left = i;
                    } else if (right == -1) {
                        right = i;
                    } else {
                        return false;
                    }
                }
            }
            return right != -1 && s[left] == goal[right] && s[right] == goal[left];
        }
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s, goal;
    bool res;
    
    /**
     输入：s = "ab", goal = "ba"
     输出：true
     解释：你可以交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 相等。
     */
    s = "ab";
    goal = "ba";
    res = true;
    assert(res == Solution().buddyStrings(s, goal));
    
    /**
     输入：s = "ab", goal = "ab"
     输出：false
     解释：你只能交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 不相等。
     */
    s = "ab";
    goal = "ab";
    res = false;
    assert(res == Solution().buddyStrings(s, goal));
    
    /**
     输入：s = "aa", goal = "aa"
     输出：true
     解释：你可以交换 s[0] = 'a' 和 s[1] = 'a' 生成 "aa"，此时 s 和 goal 相等。
     */
    s = "aa";
    goal = "aa";
    res = true;
    assert(res == Solution().buddyStrings(s, goal));
    
    /**
     输入：s = "aaaaaaabc", goal = "aaaaaaacb"
     输出：true
     */
    s = "aaaaaaabc";
    goal = "aaaaaaacb";
    res = true;
    assert(res == Solution().buddyStrings(s, goal));

    cout << "OK~" << endl;

    return 0;
}
