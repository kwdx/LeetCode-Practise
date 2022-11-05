/*
 * @lc app=leetcode.cn id=1668 lang=cpp
 *
 * [1668] 最大重复子字符串
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        string sub = word;
        while (sequence.find(sub) != sequence.npos) {
            ans += 1;
            sub += word;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string sequence;
    string word;
    int res;
    
    sequence = "aaabaaaabaaabaaaabaaaabaaaabaaaaba";
    word = "aaaba";
    res = 5;
    assert(res == Solution().maxRepeating(sequence, word));

    /**
     输入：sequence = "ababc", word = "ab"
     输出：2
     解释："abab" 是 "ababc" 的子字符串。
     */
    sequence = "ababc";
    word = "ab";
    res = 2;
    assert(res == Solution().maxRepeating(sequence, word));
    
    /**
     输入：sequence = "ababc", word = "ba"
     输出：1
     解释："ba" 是 "ababc" 的子字符串，但 "baba" 不是 "ababc" 的子字符串。
     */
    sequence = "ababc";
    word = "ba";
    res = 1;
    assert(res == Solution().maxRepeating(sequence, word));
    
    /**
     输入：sequence = "ababc", word = "ac"
     输出：0
     解释："ac" 不是 "ababc" 的子字符串。
     */
    sequence = "ababc";
    word = "ac";
    res = 0;
    assert(res == Solution().maxRepeating(sequence, word));
    
    cout << "OK~" << endl;
    
    return 0;
}
