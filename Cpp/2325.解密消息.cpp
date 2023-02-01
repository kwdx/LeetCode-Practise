/*
 * @lc app=leetcode.cn id=2325 lang=cpp
 *
 * [2325] 解密消息
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    string decodeMessage(string key, string message) {
        char cur = 'a';
        unordered_map<char, char> rules;
        for (char c : key) {
            if (c != ' ' && !rules.count(c)) {
                rules[c] = cur;
                cur += 1;
            }
        }
        
        for (char &c : message) {
            if (c != ' ') {
                c = rules[c];
            }
        }
        return message;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string key;
    string message;
    string res;
    
    /**
     输入：key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
     输出："this is a secret"
     解释：对照表如上图所示。
     提取 "the quick brown fox jumps over the lazy dog" 中每个字母的首次出现可以得到替换表。
     */
    key = "the quick brown fox jumps over the lazy dog";
    message = "vkbs bs t suepuv";
    res = "this is a secret";
    assert(res == Solution().decodeMessage(key, message));
    
    /**
     输入：key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
     输出："the five boxing wizards jump quickly"
     解释：对照表如上图所示。
     提取 "eljuxhpwnyrdgtqkviszcfmabo" 中每个字母的首次出现可以得到替换表。
     */
    key = "eljuxhpwnyrdgtqkviszcfmabo";
    message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";
    res = "the five boxing wizards jump quickly";
    assert(res == Solution().decodeMessage(key, message));

    cout << "OK~" << endl;
    
    return 0;
}
