/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

#include <iostream>
#include <vector>

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

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        insert(root, word);
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
    
    bool dfs(const string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->isEnd;
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            TrieNode* child = node->child[ch - 'a'];
            if (child && dfs(word, index + 1, child))
                return true;
        } else if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                TrieNode* child = node->child[i];
                if (child && dfs(word, index + 1, child))
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入：
     ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
     [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
     输出：
     [null,null,null,null,false,true,true,true]

     解释：
     WordDictionary wordDictionary = new WordDictionary();
     wordDictionary.addWord("bad");
     wordDictionary.addWord("dad");
     wordDictionary.addWord("mad");
     wordDictionary.search("pad"); // return False
     wordDictionary.search("bad"); // return True
     wordDictionary.search(".ad"); // return True
     wordDictionary.search("b.."); // return True
     */
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    assert(false == obj->search("pad"));
    assert(true == obj->search("bad"));
    assert(true == obj->search(".ad"));
    assert(true == obj->search("b.."));
    
    cout << "OK~" << endl;

    return 0;
}
