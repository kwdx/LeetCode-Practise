/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
struct TrieNode {
    int val;
    TrieNode * children[26];
    TrieNode() {
        this->val = 0;
        for (int i = 0; i < 26; ++i) {
            this->children[i] = nullptr;
        }
    }
};

class MapSum {
private:
    TrieNode *root;
    unordered_map<string, int> cnt;
public:
    MapSum() {
        this->root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int delta = val;
        if (cnt.count(key)) {
            delta -= cnt[key];
        }
        cnt[key] = val;
        TrieNode *node = root;
        for (auto c : key) {
            if (node->children[c - 'a'] == NULL) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
            node->val += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode *node = root;
        for (auto c : prefix) {
            if (node->children[c - 'a'] == NULL) {
                return 0;
            }
            node = node->children[c - 'a'];
        }
        return node->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入：
     ["MapSum", "insert", "sum", "insert", "sum"]
     [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
     输出：
     [null, null, 3, null, 5]

     解释：
     MapSum mapSum = new MapSum();
     mapSum.insert("apple", 3);
     mapSum.sum("ap");           // return 3 (apple = 3)
     mapSum.insert("app", 2);
     mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
     */
    MapSum* obj = new MapSum();
    obj->insert("apple", 3);
    assert(3 == obj->sum("ap"));
    obj->insert("app", 2);
    assert(5 == obj->sum("ap"));

    cout << "OK~" << endl;

    return 0;
}
