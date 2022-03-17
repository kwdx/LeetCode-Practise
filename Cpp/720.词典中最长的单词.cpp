/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Trie {
private:
    vector<Trie *> children;
    bool isEnd;
public:
    Trie() {
        this->children = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }
    
    bool insert(const string & word) {
        Trie * node = this;
        for (const auto & ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
        return true;
    }

    bool search(const string & word) {
        Trie * node = this;
        for (const auto & ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr || !node->children[index]->isEnd) {
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr && node->isEnd;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (const auto & word : words) {
            trie.insert(word);
        }
        string longest = "";
        for (const auto & word : words) {
            if (trie.search(word)) {
                if (word.size() > longest.size() ||
                    (word.size() == longest.size() && word < longest)) {
                    longest = word;
                }
            }
        }
        return longest;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> words;
    string res;
    
    /**
     输入：words = ["w","wo","wor","worl", "world"]
     输出："world"
     解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
     */
    words = {"w","wo","wor","worl", "world"};
    res = "world";
    assert(res == Solution().longestWord(words));
    
    /**
     输入：words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
     输出："apple"
     解释："apply" 和 "apple" 都能由词典中的单词组成。但是 "apple" 的字典序小于 "apply"
     */
    words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    res = "apple";
    assert(res == Solution().longestWord(words));

    cout << "OK~" << endl;

    return 0;
}
