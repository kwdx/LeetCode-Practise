/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string s) {
        string ans = s;
        int left = 0, right = (int)s.size() - 1;
        while (left <= right) {
            while (!isLetter(ans[left]) && left <= right) {
                ++left;
            }
            while (!isLetter(ans[right]) && left <= right) {
                --right;
            }
            if (left <= right) {
                swap(ans[left++], ans[right--]);
            }
        }
        return ans;
    }
    
    inline bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    string res;
    
    /**
     输入：s = "ab-cd"
     输出："dc-ba"
     */
    s = "ab-cd";
    res = "dc-ba";
    assert(res == Solution().reverseOnlyLetters(s));
    
    /**
     输入：s = "a-bC-dEf-ghIj"
     输出："j-Ih-gfE-dCba"
     */
    s = "a-bC-dEf-ghIj";
    res = "j-Ih-gfE-dCba";
    assert(res == Solution().reverseOnlyLetters(s));

    cout << "OK~" << endl;
    
    return 0;
}
