/*
 * @lc app=leetcode.cn id=1455 lang=cpp
 *
 * [1455] 检查单词是否为句中其他单词的前缀
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = (int)sentence.size();
        int m = (int)searchWord.size();
        int index = 0;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            j = 0;
            index += 1;
            while (i < n && j < m && sentence[i] == searchWord[j]) {
                ++i;
                ++j;
            }
            if (j == m) {
                return index;
            }
            while (i < n && sentence[i] != ' ') {
                ++i;
            }
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string sentence;
    string searchWord;
    int res;
    
    /**
     输入：sentence = "i love eating burger", searchWord = "burg"
     输出：4
     解释："burg" 是 "burger" 的前缀，而 "burger" 是句子中第 4 个单词。
     */
    sentence = "i love eating burger";
    searchWord = "burg";
    res = 4;
    assert(res == Solution().isPrefixOfWord(sentence, searchWord));
    
    /**
     输入：sentence = "this problem is an easy problem", searchWord = "pro"
     输出：2
     解释："pro" 是 "problem" 的前缀，而 "problem" 是句子中第 2 个也是第 6 个单词，但是应该返回最小下标 2 。
     */
    sentence = "this problem is an easy problem";
    searchWord = "pro";
    res = 2;
    assert(res == Solution().isPrefixOfWord(sentence, searchWord));
    
    /**
     输入：sentence = "i am tired", searchWord = "you"
     输出：-1
     解释："you" 不是句子中任何单词的前缀。
     */
    sentence = "i am tired";
    searchWord = "you";
    res = -1;
    assert(res == Solution().isPrefixOfWord(sentence, searchWord));

    cout << "OK~" << endl;
    
    return 0;
}
