/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        string word;
        string word1, word2;
        for (char c : text) {
            if (c == ' ') {
                // 单词
                if (word1 == first && word2 == second) {
                    ans.push_back(word);
                }
                word1 = word2;
                word2 = word;
                word = "";
            } else {
                word += c;
            }
        }
        if (word1 == first && word2 == second) {
            ans.push_back(word);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string text, first, second;
    vector<string> res;
    
    /**
     输入：text = "alice is a good girl she is a good student", first = "a", second = "good"
     输出：["girl","student"]
     */
    text = "alice is a good girl she is a good student";
    first = "a";
    second = "good";
    res = {"girl","student"};
    assert(res == Solution().findOcurrences(text, first, second));

    /**
     输入：text = "we will we will rock you", first = "we", second = "will"
     输出：["we","rock"]
     */
    text = "we will we will rock you";
    first = "we";
    second = "will";
    res = {"we","rock"};
    assert(res == Solution().findOcurrences(text, first, second));
    
    /**
     输入：text = "jkypmsxd jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa", first = "kcyxdfnoa", second = "jkypmsxd"
     输出：["kcyxdfnoa","kcyxdfnoa","kcyxdfnoa"]
     */
    text = "jkypmsxd jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa";
    first = "kcyxdfnoa";
    second = "jkypmsxd";
    res = {"kcyxdfnoa","kcyxdfnoa","kcyxdfnoa"};
    assert(res == Solution().findOcurrences(text, first, second));
    
    /**
     输入：text = "we we we we will rock you", first = "we", second = "we"
     输出：["we","we","will"]
     */
    text = "we we we we will rock you";
    first = "we";
    second = "we";
    res = {"we","we","will"};
    assert(res == Solution().findOcurrences(text, first, second));
    
    cout << "OK~" << endl;

    return 0;
}
