/*
 * @lc app=leetcode.cn id=1754 lang=cpp
 *
 * [1754] 构造字典序最大的合并字符串
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans;
        int i = 0, j = 0;
        while (i < word1.size() || j < word2.size()) {
            if (i < word1.size() && word1.substr(i) > word2.substr(j)) {
                ans.push_back(word1[i++]);
            } else {
                ans.push_back(word2[j++]);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string word1;
    string word2;
    string res;
    
    /**
     输入：word1 = "cabaa", word2 = "bcaaa"
     输出："cbcabaaaaa"
     解释：构造字典序最大的合并字符串，可行的一种方法如下所示：
     - 从 word1 中取第一个字符：merge = "c"，word1 = "abaa"，word2 = "bcaaa"
     - 从 word2 中取第一个字符：merge = "cb"，word1 = "abaa"，word2 = "caaa"
     - 从 word2 中取第一个字符：merge = "cbc"，word1 = "abaa"，word2 = "aaa"
     - 从 word1 中取第一个字符：merge = "cbca"，word1 = "baa"，word2 = "aaa"
     - 从 word1 中取第一个字符：merge = "cbcab"，word1 = "aa"，word2 = "aaa"
     - 将 word1 和 word2 中剩下的 5 个 a 附加到 merge 的末尾。
     */
    word1 = "cabaa";
    word2 = "bcaaa";
    res = "cbcabaaaaa";
    assert(res == Solution().largestMerge(word1, word2));
    
    /**
     输入：word1 = "abcabc", word2 = "abdcaba"
     输出："abdcabcabcaba"
     */
    word1 = "abcabc";
    word2 = "abdcaba";
    res = "abdcabcabcaba";
    assert(res == Solution().largestMerge(word1, word2));

    cout << "OK~" << endl;
    
    return 0;
}
