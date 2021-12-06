/*
 * @lc app=leetcode.cn id=1816 lang=cpp
 *
 * [1816] 截断句子
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = (int)s.size();
        int end = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (i == n || s[i] == ' ') {
                if (++cnt == k) {
                    end = i;
                    break;
                }
            }
        }
        return s.substr(0, end);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int k;
    string res;
    
    /**
     输入：s = "Hello how are you Contestant", k = 4
     输出："Hello how are you"
     解释：
     s 中的单词为 ["Hello", "how" "are", "you", "Contestant"]
     前 4 个单词为 ["Hello", "how", "are", "you"]
     因此，应当返回 "Hello how are you"
     */
    s = "Hello how are you Contestant";
    k = 4;
    res = "Hello how are you";
    assert(res == Solution().truncateSentence(s, k));
    
    /**
     输入：s = "What is the solution to this problem", k = 4
     输出："What is the solution"
     解释：
     s 中的单词为 ["What", "is" "the", "solution", "to", "this", "problem"]
     前 4 个单词为 ["What", "is", "the", "solution"]
     因此，应当返回 "What is the solution"
     */
    s = "What is the solution to this problem";
    k = 4;
    res = "What is the solution";
    assert(res == Solution().truncateSentence(s, k));
    
    /**
     输入：s = "chopper is not a tanuki", k = 5
     输出："chopper is not a tanuki"
     */
    s = "chopper is not a tanuki";
    k = 5;
    res = "chopper is not a tanuki";
    assert(res == Solution().truncateSentence(s, k));

    cout << "OK~" << endl;

    return 0;
}
