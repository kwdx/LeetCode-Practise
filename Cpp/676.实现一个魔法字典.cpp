/*
 * @lc app=leetcode.cn id=676 lang=cpp
 *
 * [676] 实现一个魔法字典
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class MagicDictionary {
private:
    unordered_map<int, vector<string>> map;
public:
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        for (string& word : dictionary) {
            int n = (int)word.size();
            if (!map.count(n)) {
                map[n] = vector<string>(0);
            }
            map[n].emplace_back(word);
        }
    }
    
    bool search(string searchWord) {
        int n = (int)searchWord.size();
        if (!map.count(n)) {
            return false;
        }
        vector<string> words = map[n];
        for (string& word : words) {
            int diff = 0;
            for (int i = 0; i < n; ++i) {
                if (word[i] == searchWord[i]) {
                    continue;
                }
                ++diff;
            }
            if (diff == 1) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入
     ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
     [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
     输出
     [null, null, false, true, false, false]

     解释
     MagicDictionary magicDictionary = new MagicDictionary();
     magicDictionary.buildDict(["hello", "leetcode"]);
     magicDictionary.search("hello"); // 返回 False
     magicDictionary.search("hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
     magicDictionary.search("hell"); // 返回 False
     magicDictionary.search("leetcoded"); // 返回 False
     */
    MagicDictionary *magicDictionary = new MagicDictionary();
    magicDictionary.buildDict(["hello", "leetcode"]);
    assert(false == magicDictionary.search("hello")); // 返回 False
    assert(true == magicDictionary.search("hhllo")); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
    assert(false == magicDictionary.search("hell")); // 返回 False
    assert(false == magicDictionary.search("leetcoded")); // 返回 False
    
    cout << "OK~" << endl;
    
    return 0;
}
