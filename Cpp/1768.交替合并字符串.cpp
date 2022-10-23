/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] 交替合并字符串
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int m = (int)word1.size();
        int n = (int)word2.size();
        for (int i = 0; i < min(m, n); ++i) {
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        if (m < n) {
            ans += word2.substr(m);
        } else {
            ans += word1.substr(n);
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
     输入：word1 = "abc", word2 = "pqr"
     输出："apbqcr"
     解释：字符串合并情况如下所示：
     word1：  a   b   c
     word2：    p   q   r
     合并后：  a p b q c r
     */
    word1 = "abc";
    word2 = "pqr";
    res = "apbqcr";
    assert(res == Solution().mergeAlternately(word1, word2));
    
    /**
     输入：word1 = "ab", word2 = "pqrs"
     输出："apbqrs"
     解释：注意，word2 比 word1 长，"rs" 需要追加到合并后字符串的末尾。
     word1：  a   b
     word2：    p   q   r   s
     合并后：  a p b q   r   s
     */
    word1 = "ab";
    word2 = "pqrs";
    res = "apbqrs";
    assert(res == Solution().mergeAlternately(word1, word2));
    
    /**
     输入：word1 = "abcd", word2 = "pq"
     输出："apbqcd"
     解释：注意，word1 比 word2 长，"cd" 需要追加到合并后字符串的末尾。
     word1：  a   b   c   d
     word2：    p   q
     合并后：  a p b q c   d
     */
    word1 = "abcd";
    word2 = "pq";
    res = "apbqcd";
    assert(res == Solution().mergeAlternately(word1, word2));
    
    cout << "OK~" << endl;
    
    return 0;
}
