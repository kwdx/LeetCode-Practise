/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
struct TrieNode {
    vector<TrieNode *> child;
    bool isEnd;
    TrieNode() {
        this->child = vector<TrieNode *>(26, nullptr);
        this->isEnd = false;
    }
};

void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (auto c : word) {
        if (node->child[c - 'a'] == nullptr) {
            node->child[c - 'a'] = new TrieNode();
        }
        node = node->child[c - 'a'];
    }
    node->isEnd = true;
}

class Solution {
private:
    TrieNode *root;
    bool canBeConcatenated(string& s, int idx) {
        if (idx > 0 && idx == s.length()) return true;
        TrieNode* node = root;
        for (int i = idx; i < s.length(); ++i) {
            int val = s[i] - 'a';
            if (node->child[val] == nullptr) { return false; }
            node = node->child[val];
            if (node->isEnd && canBeConcatenated(s, i + 1)) return true;
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        sort(words.begin(), words.end(), [&](string& s1, string& s2) {
            return s1.length() < s2.length();
        });
        root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            if (canBeConcatenated(words[i], 0)) {
                ans.push_back(words[i]);
            } else {
                insert(root, words[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> words;
    vector<string> res;
    
    /**
     输入：words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
     输出：["catsdogcats","dogcatsdog","ratcatdogcat"]
     解释："catsdogcats" 由 "cats", "dog" 和 "cats" 组成;
          "dogcatsdog" 由 "dog", "cats" 和 "dog" 组成;
          "ratcatdogcat" 由 "rat", "cat", "dog" 和 "cat" 组成。
     */
    words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    res = {"dogcatsdog","catsdogcats","ratcatdogcat"};
    assert(res == Solution().findAllConcatenatedWordsInADict(words));
    
    /**
     输入：words = ["cat","dog","catdog"]
     输出：["catdog"]
     */
    words = {"cat","dog","catdog"};
    res = {"catdog"};
    assert(res == Solution().findAllConcatenatedWordsInADict(words));
    
    /**
     输入：words = [""]
     输出：[]
     */
    words = {""};
    res = {};
    assert(res == Solution().findAllConcatenatedWordsInADict(words));

    cout << "OK~" << endl;

    return 0;
}
