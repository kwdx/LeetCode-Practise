/*
 * @lc app=leetcode.cn id=745 lang=cpp
 *
 * [745] 前缀和后缀搜索
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start

struct Trie {
    unordered_map<string, Trie*> children;
    int weight;
};

class WordFilter {
private:
    Trie* trie;
public:
    WordFilter(vector<string>& words) {
        trie = new Trie();
        for (int i = 0; i  < words.size(); ++i) {
            string word = words[i];
            int m = (int)word.size();
            Trie *cur = trie;
            for (int j = 0; j < m; ++j) {
                Trie* tmp = cur;
                for (int k = j; k < m; ++k) { // pref > suff
                    string key({word[k], '#'});
                    if (!tmp->children.count(key)) {
                        tmp->children[key] = new Trie();
                    }
                    tmp = tmp->children[key];
                    tmp->weight = i;
                }
                tmp = cur;
                for (int k = j; k < m; ++k) { // pref < suff
                    string key({'#', word[m - k - 1]});
                    if (!tmp->children.count(key)) {
                        tmp->children[key] = new Trie();
                    }
                    tmp = tmp->children[key];
                    tmp->weight = i;
                }
                string key({word[j], word[m - j - 1]});
                if (!cur->children.count(key)) {
                    cur->children[key] = new Trie();
                }
                cur = cur->children[key];
                cur->weight = i;
            }
        }
    }
    
    int f(string pref, string suff) {
        Trie *cur = trie;
        int m = (int)max(pref.size(), suff.size());
        for (int i = 0; i < m; ++i) {
            char c1 = i < pref.size() ? pref[i] : '#';
            char c2 = i < suff.size() ? suff[suff.size() - 1 - i] : '#';
            string key({c1, c2});
            if (!cur->children.count(key)) {
                return -1;
            }
            cur = cur->children[key];
        }
        return cur->weight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入
     ["WordFilter", "f"]
     [[["apple"]], ["a", "e"]]
     输出
     [null, 0]
     解释
     WordFilter wordFilter = new WordFilter(["apple"]);
     wordFilter.f("a", "e"); // 返回 0 ，因为下标为 0 的单词：前缀 prefix = "a" 且 后缀 suff = "e" 。
     */
    vector<string> words = {"apple"};
    WordFilter wordFilter(words);
    assert(wordFilter.f("a", "e") == 0);
    
    cout << "OK~" << endl;
    
    return 0;
}
