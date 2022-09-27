/*
 * @lc app=leetcode.cn id=check-permutation-lcci lang=cpp
 *
 * [面试题] 01.02. 判定是否互为字符重排
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        unordered_map<char, int> chars;
        for (char c : s1) {
            chars[c] += 1;
        }
        for (char c : s2) {
            chars[c] -= 1;
            if (chars[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s1;
    string s2;
    bool res;
    
    /**
     输入: s1 = "abc", s2 = "bca"
     输出: true
     */
    s1 = "abc";
    s2 = "bca";
    res = true;
    assert(res == Solution().CheckPermutation(s1, s2));
    
    /**
     输入: s1 = "abc", s2 = "bad"
     输出: false
     */
    s1 = "abc";
    s2 = "bad";
    res = false;
    assert(res == Solution().CheckPermutation(s1, s2));

    cout << "OK~" << endl;
    
    return 0;
}

