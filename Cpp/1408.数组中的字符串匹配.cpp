/*
 * @lc app=leetcode.cn id=1408 lang=cpp
 *
 * [1408] 数组中的字符串匹配
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = (int)words.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || words[i].size() == words[j].size()) {
                    continue;
                }
                if (words[j].find(words[i]) != string::npos) {
                    ans.emplace_back(words[i]);
                    break;
                }
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
     输入：words = ["mass","as","hero","superhero"]
     输出：["as","hero"]
     解释："as" 是 "mass" 的子字符串，"hero" 是 "superhero" 的子字符串。
     ["hero","as"] 也是有效的答案。
     */
    words = {"mass","as","hero","superhero"};
    res = {"as","hero"};
    assert(res == Solution().stringMatching(words));
    
    /**
     输入：words = ["leetcode","et","code"]
     输出：["et","code"]
     解释："et" 和 "code" 都是 "leetcode" 的子字符串。
     */
    words = {"leetcode","et","code"};
    res = {"et","code"};
    assert(res == Solution().stringMatching(words));
    
    /**
     输入：words = ["blue","green","bu"]
     输出：[]
     */
    words = {"blue","green","bu"};
    res = {};
    assert(res == Solution().stringMatching(words));
    
    cout << "OK~" << endl;
    
    return 0;
}
