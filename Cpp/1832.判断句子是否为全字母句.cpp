/*
 * @lc app=leetcode.cn id=1832 lang=cpp
 *
 * [1832] 判断句子是否为全字母句
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int mask = 0;
        for (char c : sentence) {
            mask |= 1 << (c - 'a');
        }
        return mask == 0x3FFFFFF;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string sentence;
    bool res;
    
    /**
     输入：sentence = "thequickbrownfoxjumpsoverthelazydog"
     输出：true
     解释：sentence 包含英语字母表中每个字母至少一次。
     */
    sentence = "thequickbrownfoxjumpsoverthelazydog";
    res = true;
    assert(res == Solution().checkIfPangram(sentence));
    
    /**
     输入：sentence = "leetcode"
     输出：false
     */
    sentence = "leetcode";
    res = false;
    assert(res == Solution().checkIfPangram(sentence));

    cout << "OK~" << endl;
    
    return 0;
}
