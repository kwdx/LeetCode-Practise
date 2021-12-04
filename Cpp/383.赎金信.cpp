/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() < ransomNote.size()) {
            return false;
        }
        unordered_map<char, int> chars;
        for (char ch : magazine) {
            ++chars[ch];
        }
        for (char ch : ransomNote) {
            if (chars[ch] <= 0) {
                return false;
            }
            --chars[ch];
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string ransomNote, magazine;
    bool res;
    
    /**
     输入：ransomNote = "a", magazine = "b"
     输出：false
     */
    ransomNote = "a";
    magazine = "b";
    res = false;
    assert(res == Solution().canConstruct(ransomNote, magazine));
    
    /**
     输入：ransomNote = "aa", magazine = "ab"
     输出：false
     */
    ransomNote = "aa";
    magazine = "ab";
    res = false;
    assert(res == Solution().canConstruct(ransomNote, magazine));
    
    /**
     输入：ransomNote = "aa", magazine = "aab"
     输出：true
     */
    ransomNote = "aa";
    magazine = "aab";
    res = true;
    assert(res == Solution().canConstruct(ransomNote, magazine));

    cout << "OK~" << endl;

    return 0;
}
