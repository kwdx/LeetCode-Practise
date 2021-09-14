/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for (string str : dictionary) {
            if (s.size() < str.size()) continue;
            int i = 0, j = 0;
            while (i < s.size() && j < str.size()) {
                if (s[i] == str[j]) {
                    ++i;
                    ++j;
                } else {
                    ++i;
                }
            }
            if (j == str.size()) {
                if (res.size() == 0) res = str;
                else if (str.size() > res.size()) res = str;
                else if (str.size() == res.size()) res = str > res ? res : str;
            };
        }

        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string s;
    vector<string> dictionary;
    string res;
    
    /**
     输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
     输出："apple"
     */
    s = "abpcplea";
    dictionary = {"ale","apple","monkey","plea"};
    res = "apple";
    assert(res == Solution().findLongestWord(s, dictionary));
    
    /**
     输入：s = "abpcplea", dictionary = ["a","b","c"]
     输出："a"
     */
    s = "abpcplea";
    dictionary = {"a","b","c"};
    res = "a";
    assert(res == Solution().findLongestWord(s, dictionary));
    
    cout << "OK~" << endl;
    
    return 0;
}
