/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        bitset<26> chars;
        for (char c : allowed) {
            chars.set(c - 'a');
        }
        for (string& word : words) {
            bool flag = true;
            for (char c: word) {
                if (chars[c - 'a'] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans += 1;
            }
        }
        return ans;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    string allowed;
    vector<string> words;
    int res;
    
    /**
     输入：allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
     输出：2
     解释：字符串 "aaab" 和 "baa" 都是一致字符串，因为它们只包含字符 'a' 和 'b' 。
     */
    allowed = "ab";
    words = {"ad","bd","aaab","baa","badab"};
    res = 2;
    assert(res == Solution().countConsistentStrings(allowed, words));
    
    /**
     输入：allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
     输出：7
     解释：所有字符串都是一致的。
     */
    allowed = "abc";
    words = {"a","b","c","ab","ac","bc","abc"};
    res = 7;
    assert(res == Solution().countConsistentStrings(allowed, words));
    
    /**
     输入：allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
     输出：4
     解释：字符串 "cc"，"acd"，"ac" 和 "d" 是一致字符串。
     */
    allowed = "cad";
    words = {"cc","acd","b","ba","bac","bad","ac","d"};
    res = 4;
    assert(res == Solution().countConsistentStrings(allowed, words));
    
    cout << "OK~" << endl;
    
    return 0;
}
