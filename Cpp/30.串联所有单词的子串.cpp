/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int m = (int)words.size(), n = (int)words[0].size();
        int ls = (int)s.size();
        for (int i = 0; i + m * n <= ls; ++i) {
            unordered_map<string, int> differ;
            for (int j = 0; j < m; ++j) {
                ++differ[s.substr(i + j * n, n)];
            }
            for (string& word : words) {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }
            if (differ.empty()) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    vector<string> words;
    vector<int> res;
    
    /**
     输入：s = "barfoothefoobarman", words = ["foo","bar"]
     输出：[0,9]
     解释：
     从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
     输出的顺序不重要, [9,0] 也是有效答案。
     */
    s = "barfoothefoobarman";
    words = {"foo","bar"};
    res = {0,9};
    assert(res == Solution().findSubstring(s, words));
    
    /**
     输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
     输出：[]
     */
    s = "wordgoodgoodgoodbestword";
    words = {"word","good","best","word"};
    res = {};
    assert(res == Solution().findSubstring(s, words));
    
    /**
     输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
     输出：[6,9,12]
     */
    s = "barfoofoobarthefoobarman";
    words = {"bar","foo","the"};
    res = {6,9,12};
    assert(res == Solution().findSubstring(s, words));
    
    cout << "OK~" << endl;
    
    return 0;
}
