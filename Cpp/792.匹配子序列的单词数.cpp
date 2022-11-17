/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - 'a'].push_back(i);
        }
        int ans = (int)words.size();
        for (auto& word : words) {
            if (word.size() > s.size()) {
                --ans;
                continue;
            }
            int p = -1;
            for (char c : word) {
                auto &ps = pos[c - 'a'];
                auto it = upper_bound(ps.begin(), ps.end(), p);
                if (it == ps.end()) {
                    --ans;
                    break;
                }
                p = *it;
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
    int res;
    
    /**
     输入: s = "abcde", words = ["a","bb","acd","ace"]
     输出: 3
     解释: 有三个是 s 的子序列的单词: "a", "acd", "ace"。
     */
    s = "abcde";
    words = {"a","bb","acd","ace"};
    res = 3;
    assert(res == Solution().numMatchingSubseq(s, words));
    
    /**
     输入: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
     输出: 2
     */
    s = "dsahjpjauf";
    words = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
    res = 2;
    assert(res == Solution().numMatchingSubseq(s, words));

    cout << "OK~" << endl;
    
    return 0;
}
