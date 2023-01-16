/*
 * @lc app=leetcode.cn id=1813 lang=cpp
 *
 * [1813] 句子相似性 III
 */

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> split(const string & str, char target) {
        vector<string> res;
        string s(str);
        int pos = 0;
        while (pos < s.size()) {
            while (pos < s.size() && s[pos] == target) {
                pos++;
            }
            int start = pos;
            while (pos < s.size() && s[pos] != target) {
                pos++;
            }
            if (pos > start) {
                res.emplace_back(s.substr(start, pos - start));
            }
        }
        return res;
    }
    
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1, ' ');
        vector<string> words2 = split(sentence2, ' ');
        int i = 0, j = 0;
        while (i < words1.size() && i < words2.size() && words1[i] == words2[i]) {
            i++;
        }
        while (j < words1.size() - i && j < words2.size() - i && words1[words1.size() - j - 1] == (words2[words2.size() - j - 1])) {
            j++;
        }
        return i + j == min(words1.size(), words2.size());
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string sentence1;
    string sentence2;
    bool res;

    /**
     输入：sentence1 = "My name is Haley", sentence2 = "My Haley"
     输出：true
     解释：可以往 sentence2 中 "My" 和 "Haley" 之间插入 "name is" ，得到 sentence1 。
     */
    sentence1 = "My name is Haley";
    sentence2 = "My Haley";
    res = true;
    assert(res == Solution().areSentencesSimilar(sentence1, sentence2));
    
    /**
     输入：sentence1 = "of", sentence2 = "A lot of words"
     输出：false
     解释：没法往这两个句子中的一个句子只插入一个句子就得到另一个句子。
     */
    sentence1 = "of";
    sentence2 = "A lot of words";
    res = false;
    assert(res == Solution().areSentencesSimilar(sentence1, sentence2));
    
    /**
     输入：sentence1 = "Eating right now", sentence2 = "Eating"
     输出：true
     解释：可以往 sentence2 的结尾插入 "right now" 得到 sentence1 。
     */
    sentence1 = "Eating right now";
    sentence2 = "Eating";
    res = true;
    assert(res == Solution().areSentencesSimilar(sentence1, sentence2));
    
    /**
     输入：sentence1 = "Luky", sentence2 = "Lucccky"
     输出：false
     */
    sentence1 = "Luky";
    sentence2 = "Lucccky";
    res = false;
    assert(res == Solution().areSentencesSimilar(sentence1, sentence2));
    
    cout << "OK~" << endl;
    
    return 0;
}
