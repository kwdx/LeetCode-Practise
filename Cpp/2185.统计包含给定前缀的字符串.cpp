/*
 * @lc app=leetcode.cn id=2185 lang=cpp
 *
 * [2185] 统计包含给定前缀的字符串
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int n = (int)pref.size();
        for (string& word : words) {
            if (word.substr(0, n) == pref) {
                ans += 1;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> words;
    string pref;
    int res;
    
    /**
     输入：words = ["pay","attention","practice","attend"], pref = "at"
     输出：2
     解释：以 "at" 作为前缀的字符串有两个，分别是："attention" 和 "attend" 。
     */
    words = {"pay","attention","practice","attend"};
    pref = "at";
    res = 2;
    assert(res == Solution().prefixCount(words, pref));
    
    /**
     输入：words = ["leetcode","win","loops","success"], pref = "code"
     输出：0
     解释：不存在以 "code" 作为前缀的字符串。
     */
    words = {"leetcode","win","loops","success"};
    pref = "code";
    res = 0;
    assert(res == Solution().prefixCount(words, pref));
    
    cout << "OK~" << endl;
    
    return 0;
}
