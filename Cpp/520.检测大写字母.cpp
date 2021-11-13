/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() >= 2 && islower(word[0]) && isupper(word[1])) {
            return false;
        }
        for (int i = 2; i < word.size(); ++i) {
            if (islower(word[i]) != islower(word[1])) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string word;
    bool res;
    
    /**
     输入：word = "USA"
     输出：true
     */
    word = "USA";
    res = true;
    assert(res == Solution().detectCapitalUse(word));
    
    /**
     输入：word = "FlaG"
     输出：false
     */
    word = "FlaG";
    res = false;
    assert(res == Solution().detectCapitalUse(word));

    cout << "OK~" << endl;

    return 0;
}
