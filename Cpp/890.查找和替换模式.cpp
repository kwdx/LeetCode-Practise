/*
 * @lc app=leetcode.cn id=890 lang=cpp
 *
 * [890] 查找和替换模式
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, char> maps;
        string p;
        char cur = 'A';
        for (char c : pattern) {
            if (!maps.count(c)) {
                maps[c] = cur++;
            }
            p += maps[c];
        }
        vector<string> ans;
        for (string& word : words) {
            maps.clear();
            cur = 'A';
            string tmp = "";
            for (char c : word) {
                if (!maps.count(c)) {
                    maps[c] = cur++;
                }
                tmp += maps[c];
            }
            if (tmp == p) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> words;
    string pattern;
    vector<string> res;
    
    /**
     输入：words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
     输出：["mee","aqq"]
     解释：
     "mee" 与模式匹配，因为存在排列 {a -> m, b -> e, ...}。
     "ccc" 与模式不匹配，因为 {a -> c, b -> c, ...} 不是排列。
     因为 a 和 b 映射到同一个字母。
     */
    words = {"abc","deq","mee","aqq","dkd","ccc"};
    pattern = "abb";
    res = {"mee","aqq"};
    assert(res == Solution().findAndReplacePattern(words, pattern));

    cout << "OK~" << endl;
    
    return 0;
}
