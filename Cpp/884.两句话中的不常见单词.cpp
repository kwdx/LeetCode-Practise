/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        auto insert = [&](const string& s) {
            stringstream ss(s);
            string word;
            while (ss >> word) {
                ++freq[move(word)];
            }
        };

        insert(s1);
        insert(s2);

        vector<string> ans;
        for (const auto& it: freq) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s1;
    string s2;
    vector<string> res;
    
    /**
     输入：s1 = "this apple is sweet", s2 = "this apple is sour"
     输出：["sweet","sour"]
     */
    s1 = "this apple is sweet";
    s2 = "this apple is sour";
    res = {"sweet","sour"};
    assert(res == Solution().uncommonFromSentences(s1, s2));
    
    /**
     输入：s1 = "apple apple", s2 = "banana"
     输出：["banana"]
     */
    s1 = "apple apple";
    s2 = "banana";
    res = {"banana"};
    assert(res == Solution().uncommonFromSentences(s1, s2));

    cout << "OK~" << endl;

    return 0;
}
