/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Trie {
public:
    vector<Trie*> children;
    bool isEnd;
    Trie() : children(26), isEnd(false) {}
    
    void insert(string& word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new Trie();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    string find(string word) {
        string ans;
        Trie* node = this;
        for (char c : word) {
            if (node->children[c - 'a']) {
                ans += c;
                node = node->children[c - 'a'];
            } else {
                break;
            }
            if (node->isEnd) {
                break;
            }
        }
        return node->isEnd ? ans : "";
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        Trie* root = new Trie();
        for (string& word : dictionary) {
            root->insert(word);
        }
        string word;
        for (char c : sentence) {
            if (c == ' ') {
                string res = root->find(word);
                if (!res.empty()) {
                    ans += res + ' ';
                } else {
                    ans += word + ' ';
                }
                word = "";
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            string res = root->find(word);
            if (!res.empty()) {
                ans += res + ' ';
            } else {
                ans += word + ' ';
            }
        }
        if (!ans.empty()) {
            ans = ans.substr(0, ans.size() - 1);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> dictionary;
    string sentence;
    string res;
    
    /**
     输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
     输出："the cat was rat by the bat"
     */
    dictionary = {"cat","bat","rat"};
    sentence = "the cattle was rattled by the battery";
    res = "the cat was rat by the bat";
    assert(res == Solution().replaceWords(dictionary, sentence));
    
    /**
     输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
     输出："a a b c"
     */
    dictionary = {"a","b","c"};
    sentence = "aadsfasf absbs bbab cadsfafs";
    res = "a a b c";
    assert(res == Solution().replaceWords(dictionary, sentence));
    
    cout << "OK~" << endl;
    
    return 0;
}
