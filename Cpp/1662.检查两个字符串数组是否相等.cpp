/*
 * @lc app=leetcode.cn id=1662 lang=cpp
 *
 * [1662] 检查两个字符串数组是否相等
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return join(word1) == join(word2);
    }
private:
    string join(vector<string>& words) {
        string ans;
        for (string& word : words) {
            ans += word;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> word1;
    vector<string> word2;
    bool res;
    
    /**
     输入：word1 = ["ab", "c"], word2 = ["a", "bc"]
     输出：true
     解释：
     word1 表示的字符串为 "ab" + "c" -> "abc"
     word2 表示的字符串为 "a" + "bc" -> "abc"
     两个字符串相同，返回 true
     */
    word1 = {"ab", "c"};
    word2 = {"a", "bc"};
    res = true;
    assert(res == Solution().arrayStringsAreEqual(word1, word2));
    
    /**
     输入：word1 = ["a", "cb"], word2 = ["ab", "c"]
     输出：false
     */
    word1 = {"a", "cb"};
    word2 = {"ab", "c"};
    res = false;
    assert(res == Solution().arrayStringsAreEqual(word1, word2));
    
    /**
     输入：word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
     输出：true
     */
    word1 = {"abc", "d", "defg"};
    word2 = {"abcddefg"};
    res = true;
    assert(res == Solution().arrayStringsAreEqual(word1, word2));
    
    cout << "OK~" << endl;
    
    return 0;
}
